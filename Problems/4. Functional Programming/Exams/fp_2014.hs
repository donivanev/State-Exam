-- А) Напишете функция totalMin, която за списък от едноместни числови функции връща тази функция݂ f от списъка,
-- за която݂ f(0) е минимално.
-- Б) Напишете функция chainMinCompositions, която получава като аргумент едноместна числова функция f и генерира
-- безкрайния поток (за Хаскел – безкрайния списък) F₀, F₁, F₂, ... където:
--  F₀ = id
--  F₁ = f
--  Fᵢ = Fᵢ₋₁ ◦ Fᵢ₋₂, ако i > 1 и Fᵢ₋₁(j) ≠ Fᵢ₋₂(j), за някое цяло число j ∈ [0, i]
-- Забележка: с id е означена функцията "идентитет", като id(x) = x за произволно x, а с f ◦ g е означена композицията
-- на функциите на f и g, като (f ◦ g)(x) = f(g(x))

totalMin :: [Int -> Int] -> (Int -> Int)
totalMin fs = minimumBy (\f g -> compare (f 0) (g 0)) fs

chainMinCompositions :: (Int -> Int) -> [Int -> Int]
chainMinCompositions f = go [id, f] 2
  where
    go fs i =
      let f1 = fs !! (i - 1)
          f2 = fs !! (i - 2)
          test j = (f1 j /= f2 j)
          inputs = [0 .. i]
      in if any test inputs
         then let fi = f1 . f2
              in fs ++ go [fi] (i + 1)
         else fs

-- Нека е даден списък L, който може да съдържа елементи от произволен тип. Напишете функция permutations, която получава
-- такъв списък и връща списък с всички пермутации (възможни пренареждания) на неговите елементи. Резултатът да се върне
-- като списък от списъци, в който всеки подсписък представя една пермутация на елементите на L
-- Пример (Haskell): permutations [1,2,3] → [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]

permutations :: [a] -> [[a]]
permutations [] = [[]]
permutations xs = [ y:zs | (y, ys) <- select xs, zs <- permutations ys ]
  where
    select []     = []
    select (x:xs) = (x, xs) : [ (y, x:ys) | (y, ys) <- select xs ]