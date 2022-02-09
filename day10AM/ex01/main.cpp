#include "LittleHand.hpp"
#include "Lemon.hpp"
#include "Banana.hpp"
#include "Lime.hpp"

int main(void)
{
    FruitBox lemonbox(5);
    FruitBox bananabox(5);
    FruitBox limebox(6);
    FruitBox Box(200);
    LittleHand test;

    Lemon *lemon = new Lemon;
    Banana *banana = new Banana;
    Lime *lime = new Lime;

    Box.putFruit(lemon);
    Box.putFruit(lemon);
    Box.putFruit(lemon);
    Box.putFruit(lemon);
    Box.putFruit(lemon);
    Box.putFruit(lime);
    Box.putFruit(lime);
    Box.putFruit(lime);
    Box.putFruit(lime);
    Box.putFruit(lime);
    Box.putFruit(banana);
    Box.putFruit(banana);
    Box.putFruit(banana);
    Box.putFruit(banana);
    Box.putFruit(banana);
    Box.putFruit(banana);
    Box.putFruit(banana);
    Box.putFruit(lime);
    Box.putFruit(lime);
    Box.putFruit(lime);
    Box.putFruit(lime);


    test.sortFruitBox(Box, lemonbox, bananabox, limebox);
    Box.printlist();
    printf("\n");
    lemonbox.printlist();

}