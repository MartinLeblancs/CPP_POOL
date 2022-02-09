mySucc :: Int -> Int
mySucc nb = nb + 1

myIsNeg :: Int -> Bool
myIsNeg nb = nb < 0

myAbs :: Int -> Int
myAbs nb
    | nb < 0 = nb * (-1)
    | otherwise = nb

myMin :: Int -> Int -> Int
myMin nb1 nb2
    | nb1 < nb2 = nb1
    | otherwise = nb2

myMax :: Int -> Int -> Int
myMax nb1 nb2
    | nb1 > nb2 = nb1
    | otherwise = nb2

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)


myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (x:end) = x
myHead [] = error "Empty List"

myTail :: [a] -> [a]
myTail (x:end) = end
myTail [] = error "Empty List"

myLength :: [a] -> Int
myLength (x:end) = myLength (end) + 1
myLength [] = 0

myNth :: [a] -> Int -> a
myNth a 0 = myHead (a)
myNth (x:xs) nb
    | myLength (x:xs) == 0 = error "Empty List"
    | nb >= myLength (x:xs) = error "The index is too large"
    | nb < 0 = error "The index can't be negative"
    | otherwise = myNth xs (nb - 1) 


myTake :: Int -> [a] -> [a]
myTake 0 _ = []
myTake nb (x:xs)
    | myLength (x:xs) == 0 = error "Empty List"
    | nb < 0 = error "The index can't be negative" 
    | nb >= myLength (x:xs) = (x:xs)
    | otherwise = x : myTake (nb - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop 0 xs = xs
myDrop nb (x:xs)
    | myLength (x:xs) == 0 = error "Empty List"
    | myLength (x:xs) <= nb = (x:xs)
    | nb < 0 = error "The index can't be negative"
    | otherwise  = myDrop (nb - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] x = x
myAppend (x:xs) list = x : myAppend xs list