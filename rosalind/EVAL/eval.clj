(ns prob-stuf
  (:use clojure.test))

(defn pow [x n]
  (reduce * (repeat n x)))

(defn probability-of-motif-in-dna-string [n m gc]
  (let [c_or_g (/ gc 2) a_or_t (/ (- 1 gc) 2)]
    (let [probability_sum (+ (* 2 c_or_g c_or_g) (* 2 a_or_t a_or_t))]
      (* (+ (- n m) 1) (pow probability_sum m)))))

(defn rosalind-formatted-number [n]
  (format "%.4f" n))

(defn handle-multiple-inputs [m n gc]
  (->> gc
    (map #(probability-of-motif-in-dna-string n m %)) 
    (map rosalind-formatted-number)))

(defn handle-io []
  (let [lines (map read-string (clojure.string/split (slurp "input") #"\s+"))]
    (handle-multiple-inputs (first lines) (nth lines 1) (nthrest lines 2))))

(println (handle-io))

(deftest multiple-test
  (is (= ["0.7177" "0.5917" "1.0781"] (handle-multiple-inputs 2 10 [0.32 0.42 0.81]))))

(deftest power-test
  (is (= 8 (pow 2 3)))
  (is (= 16 (pow 2 4))))

(run-tests)
