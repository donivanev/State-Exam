[ x : [x] | x <- [[1,2], [3,4]] ]
-- Оценка: [ [[1, 2], [1, 2]], [[3, 4], [3, 4]] ]

[ map (f 5) [1,2,3] | f <- [(+), (-), (*)] ]
-- Оценка: [[6, 7, 8], [-4, -3, -2], [5, 10, 15]]

"a" : [ ['b', 'c'], "d" ]
-- Оценка: ["a", "bc", "d"]

-- _____________________________________________

filterByChar c ls = filter (elem c) ls
filterByChar c ls = filter (\word -> c `elem` word) ls
-- Израз: filterByChar 'o' ["cat", "cow", "dog"]
-- Оценка: ["cow", "dog"]

let (x:y):z = ["Curry"] in (x, y, z)
-- Оценка: Error