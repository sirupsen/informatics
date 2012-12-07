    require 'rest-client'

    while(protein = $stdin.gets)
      protein.strip!
      seq = RestClient.get("http://www.uniprot.org/uniprot/#{protein}.fasta").body.split("\n")[1..-1].join("")

      puts protein
      puts seq
    end
