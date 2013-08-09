    #include<iostream>
    #include<map>
    using namespace std;

    map<string, char> codons;


    int main()
    {
      string mrna;
      cin >> mrna;

      codons[string("UUU")] = 'F';

      codons[string("CUU")] = 'L'; codons[string("AUU")] = 'I'; codons[string("GUU")] = 'V'; codons[string("UUC")] = 'F'; codons[string("CUC")] = 'L'; codons[string("AUC")] = 'I'; codons[string("GUC")] = 'V'; codons[string("UUA")] = 'L'; codons[string("CUA")] = 'L'; codons[string("AUA")] = 'I'; codons[string("GUA")] = 'V'; codons[string("UUG")] = 'L'; codons[string("CUG")] = 'L'; codons[string("AUG")] = 'M'; codons[string("GUG")] = 'V'; codons[string("UCU")] = 'S'; codons[string("CCU")] = 'P'; codons[string("ACU")] = 'T'; codons[string("GCU")] = 'A'; codons[string("UCC")] = 'S'; codons[string("CCC")] = 'P'; codons[string("ACC")] = 'T'; codons[string("GCC")] = 'A'; codons[string("UCA")] = 'S'; codons[string("CCA")] = 'P'; codons[string("ACA")] = 'T'; codons[string("GCA")] = 'A'; codons[string("UCG")] = 'S'; codons[string("CCG")] = 'P'; codons[string("ACG")] = 'T'; codons[string("GCG")] = 'A'; codons[string("UAU")] = 'Y'; codons[string("CAU")] = 'H'; codons[string("AAU")] = 'N'; codons[string("GAU")] = 'D'; codons[string("UAC")] = 'Y'; codons[string("CAC")] = 'H'; codons[string("AAC")] = 'N'; codons[string("GAC")] = 'D'; codons[string("UAA")] = 'Z'; codons[string("CAA")] = 'Q'; codons[string("AAA")] = 'K'; codons[string("GAA")] = 'E'; codons[string("UAG")] = 'Z'; codons[string("CAG")] = 'Q'; codons[string("AAG")] = 'K'; codons[string("GAG")] = 'E'; codons[string("UGU")] = 'C'; codons[string("CGU")] = 'R'; codons[string("AGU")] = 'S'; codons[string("GGU")] = 'G'; codons[string("UGC")] = 'C'; codons[string("CGC")] = 'R'; codons[string("AGC")] = 'S'; codons[string("GGC")] = 'G'; codons[string("UGA")] = 'Z'; codons[string("CGA")] = 'R'; codons[string("AGA")] = 'R'; codons[string("GGA")] = 'G'; codons[string("UGG")] = 'W'; codons[string("CGG")] = 'R'; codons[string("AGG")] = 'R'; codons[string("GGG")] = 'G';

      for(int i = 0; i < mrna.size(); i += 3) {
        char amino_acid = codons[mrna.substr(i, 3)];
        if(amino_acid != 'Z') cout << amino_acid;
        else break;
      }
      cout << endl;

      return 0;
    }
