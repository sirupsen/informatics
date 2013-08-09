(defn substring-indices [string substring]
  (loop [offset 0
         indices []]
    (let [new-index (.indexOf string substring offset)]
      (if (not (neg? new-index))
        (recur (inc new-index) (conj indices (inc new-index)))
        indices))))

(println (substring-indices (str (read)) (str (read))))
