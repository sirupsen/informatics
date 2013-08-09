require "net/https"
require "uri"
require 'json'

def request(url)
  uri = URI.parse(url)
  http = Net::HTTP.new(uri.host, uri.port)
  http.use_ssl = true
  http.verify_mode = OpenSSL::SSL::VERIFY_NONE

  request = Net::HTTP::Get.new(uri.request_uri)

  response = http.request(request)
  JSON.parse(response.body)
end

class Profile
  attr_accessor :followers, :screen_name
  attr_reader :parent

  def initialize(id, parent)
    @id = id
    @parent = parent if parent
  end

  def followers
    @followers ||= get_followers
  end

  def id
    return @id if @id
    @id = request("https://api.twitter.com/1/users/show.json?screen_name=#{@screen_name}&include_entities=true")["id"]
  end

  def screen_name
    @screen_name ||= request("https://api.twitter.com/1/users/show.json?user_id=#{id}&include_entities=true")["screen_name"]
  end

  def bfs(target_id)
    queue = [self]
    target = nil

    while queue.any?
      follower = queue.shift
      #puts "Searching #{follower.id}.."
      target = follower.search_for_target(target_id)

      queue = [] and next if target
      queue += followers if followers
    end

    target.root
  end

  def search_for_target(target_id)
    followers && followers.find { |follower| follower.id == target_id }
  end

  def root
    puts parent.screen_name
    parent.root if parent.parent
  end
  
  private
  def get_followers
    result = request("https://api.twitter.com/1/followers/ids.json?cursor=-1&user_id=#{id}")["ids"]
    return result.map { |id| Profile.new(id, self) } if result

    result
  end
end

root = Profile.new(nil, nil)
root.screen_name = "sirupsen"

target_screen_name = "LaurindaGichki2"
target_id = request("https://api.twitter.com/1/users/show.json?screen_name=#{target_screen_name}&include_entities=true")["id"]

root.bfs(target_id)
