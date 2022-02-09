module ErrorHandling where

import System.Environment
import System.Exit
import Text.Read

checkInstRotate :: [String] -> Bool
checkInstRotate [] = True
checkInstRotate (x:xs) = case x of
    "ra" -> checkInstSwitch xs
    "rb" -> checkInstSwitch xs
    "rr" -> checkInstSwitch xs
    "rra" -> checkInstSwitch xs
    "rrb" -> checkInstSwitch xs
    "rrr" -> checkInstSwitch xs
    _ -> False

checkInstSwitch :: [String] -> Bool
checkInstSwitch [] = True
checkInstSwitch (x:xs) = case x of
    "sa" -> checkInstSwitch xs
    "sb" -> checkInstSwitch xs
    "sc" -> checkInstSwitch xs
    "pa" -> checkInstSwitch xs
    "pb" -> checkInstSwitch xs
    "" -> checkInstSwitch xs
    _ -> checkInstRotate (x:xs)

checkArgs :: [Maybe Int] -> Bool
checkArgs [] = True
checkArgs (x:xs) = case x of
    Nothing -> False
    _ -> checkArgs xs

errorHandling :: [String] -> [Maybe Int] -> Bool
errorHandling _ [] = False
errorHandling a x = checkInstSwitch a && checkArgs x