(def cells (map read-string (vec (flatten (cons (clojure.string/split (read-line) #"\s+") (clojure.string/split (read-line) #"\s+"))))))

(defn next-cell [cell]
  (cond
    (= cell 0) 2
    (= cell 1) 0
    (= cell 2) 3
    (= cell 3) 1))

(defn maximum-turn [a b c d turns]
  (let [table-value (+ (/ (cells a) (cells b)) (/ (cells c) (cells d)))]
    (println (str "Turn " turns " with value " table-value))
    (if (= 1 turns)
      0
      (max
        table-value
        (maximum-turn (next-cell a) (next-cell b) (next-cell c) (next-cell d) (dec turns))))))

(defn max-round [a b c d maximum rounds]
  (let [value (+ (/ (cells a) (cells b)) (/ (cells c) (cells d)))]
    (println (str value " is the value of round " rounds))
    (if (= value maximum)
      rounds
      (max-round (next-cell a) (next-cell b) (next-cell c) (next-cell d) maximum (inc rounds)))))

(let [maximum (maximum-turn 0 2 1 3 4)]
  (println)
  (println (str "Global maximum is " maximum))
  (println (max-round 0 2 1 3 maximum 0)))
