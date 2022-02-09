module Function where

import System.Environment
import System.Exit
import Text.Read

makeRotation :: [String] -> ([Int], [Int]) -> ([Int], [Int])
makeRotation [] (first, second) = (first, second)
makeRotation (str:rest) (first, second) = case str of
    "ra" -> makeOperations rest (ra (first, second))
    "rb" -> makeOperations rest (rb (first, second))
    "rr" -> makeOperations rest (rr (first, second))
    "rra" -> makeOperations rest (rra (first, second))
    "rrb" -> makeOperations rest (rrb (first, second))
    "rrr" -> makeOperations rest (rrr (first, second))

makeOperations :: [String] -> ([Int], [Int]) -> ([Int], [Int])
makeOperations [] (first, second) = (first, second) -- Stop if rest is null (no more cmd)
makeOperations (str:rest) (first, second) = case str of
    "sa" -> makeOperations rest (sa (first, second))
    "sb" -> makeOperations rest (sb (first, second))
    "sc" -> makeOperations rest (sc (first, second))
    "pa" -> makeOperations rest (pa (first, second))
    "pb" -> makeOperations rest (pb (first, second))
    otherwise -> (makeRotation (str:rest) (first, second))

printFinal :: ([Int], [Int]) -> IO ()
printFinal a | check_order a == True = putStrLn $ id "OK"
             | otherwise = putStrLn $ id "KO: " ++ show a

node :: [String] -> ([Int], [Int]) -> IO()
node a b = printFinal (makeOperations a b)

-- Functions for transforming
-- Swap the first two elements of l_a
sa :: ([a], [a]) -> ([a], [a])
sa ((first:second:rest), list) = ((second:first:rest), list)
sa a = a

-- Swap the first two elements of l_b
sb :: ([a], [a]) -> ([a], [a])
sb (list, (first:second:rest)) = (list, (second:first:rest))
sb a = a

-- sa and sb at the same time
sc :: ([a], [a]) -> ([a], [a])
sc x = sa (sb x)

-- Take the first element from l_b and move it to the first position on the l_a list
pa :: ([a], [a]) -> ([a], [a])
pa (list, (first:rest)) = (([first] ++ list), rest)
pa a = a

-- Take the first element from l_a and move it to the first position on the l_b list
pb :: ([a], [a]) -> ([a], [a])
pb ((first:rst), secondlist) = (rst,([first] ++ secondlist))
pb a = a

-- Rotate l_a toward the beginning, the first element will become the last.
ra :: ([a], [a]) -> ([a], [a])
ra ((first:rest), list) = ((rest++[first]), list)
ra a = a

-- Rotate l_b toward the beginning, the first element will become the last.
rb :: ([a], [a]) -> ([a], [a])
rb (list, (first:rest)) = (list, (rest++[first]))
rb a = a

-- ra and rb at the same time.
rr :: ([a], [a]) -> ([a], [a])
rr x = ra (rb x)

-- Rotate l_a toward the end, the last element will become the first
rra :: ([a], [a]) -> ([a], [a])
rra ([], secondlist) = ([], secondlist)
rra (list, secondlist) = (((last list):(init list)), secondlist)

-- Rotate l_b toward the end, the last element will become the first
rrb :: ([a], [a]) -> ([a], [a])
rrb (list, []) = (list, [])
rrb (list, secondlist) = (list, ((last secondlist):(init secondlist)))

-- rra and rrb at the same time.
rrr :: ([a], [a]) -> ([a], [a])
rrr x = rra (rrb x)

-- End Functions for transforming

check_order :: ([Int], [a]) -> Bool
check_order ([], [a]) = True
check_order ([x], a) = True
check_order (x:y:xs, a)
        |length a > 0 = False
        | x <= y = check_order ((y:xs), a)
        | otherwise = False