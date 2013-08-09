(defn bases-at-index [base index dna-strings]
  (loop [occurance 0 dna-string-index 0]
    (recur 
      (if 
        (= (get dna-string index) base) (inc occurance) occurance )
        (inc dna-string-index))
