#include "./Game/game.h"

//*DONE: вынести графику в отдельный класс (бизнес логика отдельно от графики) (спрайты и тд)
//*DONE: создать файл конфига со всеми константами (в частности с полем) (а лучше хранить в txt и читать с файла)
//!: расписать отчёт подробнее
//*DONE: поменять стрелочку от интерфейса
//*DONE: не читать из файла текстуру в конструкторе
//*DONE: интерфейс должен быть элемента entity, а не самой клетки
//*DONE: нет доступа к клетке из поля
//*DONE: добавить проверку валидности типа клетки, передающегося в конструкторе

int main(int argc, char const *argv[])
{
    Game game;
    game.run();
    return 0;
}