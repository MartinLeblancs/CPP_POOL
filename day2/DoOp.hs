import Data.Char
import Prelude

myElem :: Eq a => a -> [a] -> Bool
myElem nb [] = False
myElem nb (x:xs)
    | nb == x = True
    | otherwise = myElem nb (xs)    

safeDiv :: Int -> Int -> Maybe Int
safeDiv a 0 = Nothing
safeDiv nb1 nb2 = Just (nb1 `div` nb2)

safeNth :: [a] -> Int -> Maybe a
safeNth [] nb = Nothing
safeNth (x:xs) 0 = Just x
safeNth (x:xs) nb = safeNth xs (nb - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just nb) = Just (nb + 1)

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup nb [] = Nothing
myLookup nb ((a,b):xs)  
        | nb == a = Just b
        | otherwise = myLookup nb xs
        
maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo op _ Nothing = Nothing 
maybeDo op Nothing _ = Nothing 
maybeDo op (Just x) (Just y) = Just ( op x y )

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt str 
        | all isDigit str = Just (read str :: Int)
        | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do 
        s <- getLine
        return (length s)