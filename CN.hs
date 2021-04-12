module CN where

ex3 :: [Int] -> String
ex3 v = do
    if length v == 1 then
         if even (head v) then "Even" else "Odd"
    else 
        if head v `rem` v !! 1 == 0 then "Multiple" else "Not multiple"

average :: [Double] -> Double
average v = sum v / fromIntegral (length v)

isEquivalent :: [Double] -> Bool
isEquivalent v = do
    --vector size
    let n = fromIntegral $ length v
    --sum of absolute values - norm 1
    let n1 = sum [abs x | x <- v]
    --square root of sum of absolute values - norm 2
    let n2 = sqrt $ sum [abs x*x | x <- v]
    --max absolute value - norm infinity
    let n_inf = maximum v
    --norm check
    n_inf <= n2 && n2 <= sqrt (n*n_inf)
        &&  n2 <= n1 && n1 <= sqrt n * n2
        &&  n_inf <= n1 && n1 <= n*n_inf

