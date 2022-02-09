module Main where

import System.Environment
import System.Exit
import Function
import ErrorHandling
import Text.Read
import Data.Maybe

main :: IO ()   
main = do
    takeInfo <- getLine
    takeArgs <- getArgs
    let infos = words takeInfo
    let args = map (readMaybe :: String -> Maybe Int) takeArgs
    case (errorHandling infos args) of
        False -> exitWith (ExitFailure 84)
        True -> node infos ((map fromJust args), [])