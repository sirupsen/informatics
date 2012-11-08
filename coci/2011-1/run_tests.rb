require 'colored'
require 'pry'

$file = ARGV[0]

def header(test)
  puts "-------> ".blue + "Running test ##{test[:number]}.."
end

def run_test(test)
  past = Time.now
  program_output = `./#{$file} < #{test[:input]}`.strip
  present = Time.now
  elapsed = present - past

  expected_output = File.read(test[:output]).strip

  if elapsed > 1.00
    puts "\t Time: #{elapsed}".red
  else
    puts "\t Time: #{elapsed}".green
  end

  if program_output == expected_output
    puts "\t Output: #{program_output}".yellow
    puts "\t Expected: #{expected_output}".green
  else
    puts "\t Output: #{program_output}".yellow
    puts "\t Expected: #{expected_output}".red
    # puts "\t Test: #{File.read(test[:input]).strip}".red
  end

end

tests = Dir["./tests/#{$file}/*in*"].map do |file|
  {
    :input => file,
    :output => file.gsub("in", "out"),
    :number => file[/[0-9]*$/].to_i
  }
end

tests.sort! { |a, b| a[:number] <=> b[:number] }

compile = system("clang++ #{$file}.cpp -o #{$file}")

if compile
  tests.each do |test|
    header(test)
    run_test(test)
  end
end
