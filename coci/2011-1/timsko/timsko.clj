(defn abs
  ([n] (if (> n 0) n (- n))))

(defn floor
  ([n] (long n)))

(defn ceil 
  ([n] (if (> n (long n)) 
         (+ (floor n) 1)
         (long n))))

(defn solve
  ([m n k]
   (if (> (* n 2) m)
     )

(println (solve 5 3 2))
