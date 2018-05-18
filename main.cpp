#include "CompHeader.h"

void GetMenu(Perechen& ExampleComputer, bool exitFlag){
	int SwitchChoose = 1;
	std::cout << "\033c"; // clear terminal
	//system("clear");
	std::cout << "1. Загрузка файла\n2. Сохранение результатов обработки в файл\n" <<
		     "3. Добавление записи\n4. Удаление записи\n" <<
		     "5. Вывод на экран\n6. Сортировка по типу процессора и тактовой частоте\n" <<
		     "7. Алфавитная сортировка по названию марки\n8. Числовая сортировка по цене\n" <<
		     "9. Показать 1 перечень имен процессора\n10. Показать 2 перечень типов процессора\n" <<
		     "11. Показать 3 перечень объемов видеокарты\n12. Загрузить первый перечень\n" <<
		     "13. Загрузить второй перечень\n14. Загрузить третий перечень\n" <<
		     "15. Сортировать перечень 1\n16. Сортировать перечень 2\n" <<
		     "17. Сортировать перечень 3\n18. Сохранить перечни\n" <<
		     "19. Поиск по цене\n20. Поиск по объему жесткого диска\n" <<
		     "21. Поиск по названию марки, типу процессора ит.д.\n22. Сортировка результатов поиска\n" <<
		     "23. Сохранение результатов поиска\n";

	while (SwitchChoose == 1){
		std::cout << "Введите пункт меню: ";
		std::cin >> SwitchChoose;
		std::cout << "\n";
		switch(SwitchChoose){
			case 1: ExampleComputer.InputFromFile(); break;
			case 2: ExampleComputer.workComputers::OutputInFile(); break;
			case 3: ExampleComputer.Add_comp(); break;
			case 4: ExampleComputer.Delete_comp(); break;
			case 5: ExampleComputer.workComputers::showInfo(); break;
			case 6: ExampleComputer.workComputers::SortProcTypeAndClock(); break;
			case 7: ExampleComputer.workComputers::SortProcName(); break; 	
			case 8:	ExampleComputer.SortPrice(); break;
			case 9: ExampleComputer.showFirstPerech(); break;
			case 10: ExampleComputer.showSecondPerech(); break; 
			case 11: ExampleComputer.showThirdPerech();break; 
			case 12: makePerechen1(ExampleComputer, ExampleComputer); break; 
			case 13: makePerechen2(ExampleComputer, ExampleComputer);break; 
			case 14: makePerechen3(ExampleComputer, ExampleComputer);break; 
			case 15: ExampleComputer.sortProcTypeFirstPerech(); break;
			case 16: ExampleComputer.sortCountSecondPerech();break; 
			case 17: ExampleComputer.sortVideoVolumeThirdPerech(); break; 
			case 18: {
					 std::cout << "1. Сохранить 1\n 2. Сохранить 2\n 3. Сохранить 3\n";
					 int j;
					 std::cin >> j;
					 switch(j){
						 case 1: ExampleComputer.saveFirstPerech(); break;
						 case 2: ExampleComputer.saveSecondPerech(); break;
						 case 3: ExampleComputer.saveThirdPerech(); break;
						 default: break;
					 }
					 break;
			}
				 
			case 19: ExampleComputer.SearchPrice(); break;
				 
			case 20: ExampleComputer.SearchHddVolume(); break;
			case 21: ExampleComputer.SearchBrandTypeRamETC(); break;
			case 22:{
					std::cout << "1.Сорт по Типу процессора\n2. Сорт по объему ОЗУ\n";
					int c;
					std::cin >> c;
					switch(c){
						case 1: ExampleComputer.SearchComp::SortProcTypeAndClock(); break;
						case 2: ExampleComputer.SearchComp::SortRAM(); break;
					}
				}
		case 23: ExampleComputer.SearchComp::OutputInFile(); break;
		default: exitFlag =false;
	}
	std::cout << "\nВведите 1 для повторного выбора пункта меню(без очистки экрана): ";
	std::cin >> SwitchChoose; // 
}

}

int main()
{
	Perechen go;
	bool flag = true;
	while(flag)
		GetMenu(go, flag);
	std::cout << "check\n";
	return 0;
}
