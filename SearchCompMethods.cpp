#include "CompHeader.h"

void swap(SearchComp& first, SearchComp& second){
	std::swap(first.size, second.size);
	std::swap(first.SearchResult, second.SearchResult);
}

SearchComp::SearchComp(const SearchComp& copy) : SearchComp(copy.size){
	std::copy(copy.SearchResult, copy.SearchResult + size, SearchResult);
}

SearchComp& SearchComp::operator=(SearchComp copy){
	if(&copy != this)
		swap(*this, copy);
	return *this;
}

void SearchComp::testCopyOperator(){
	SearchComp eg;
	std::cout << "введите первый массив:\n";
	eg.InputFromFile();
	eg.workComputers::showInfo();
	eg.SearchPrice();
	if (true){
		SearchComp eg2;
		std::cout << "введите второй массив:\n";
		eg2.InputFromFile();
		eg2.workComputers::showInfo();
		eg2.SearchPrice();
		eg = eg2;
	}
	std::cout << "очистка второго массива\n";
	eg.showInfo();
}

void SearchComp::testCopyConstructor(){
	SearchComp eg;
	std::cout << "введите первый массив:\n";
	eg.InputFromFile();
	eg.workComputers::showInfo();
	eg.SearchPrice();
	SearchComp eg2(eg);
	std::cout << "первый массив удален\n";
	eg2.showInfo();
}
/*void SearchComp::swapElementsInVector(unsigned index){
	RECORD temp = SearchResult[index];
	SearchResult[index] = SearchResult[index - 1];
	SearchResult[index - 1] = temp;
}*/

void SearchComp::OutputInFile(){
	std::string file;
	std::cout << "Введите имя файла для сохранения\n";
	std::cin >> file;
	std::ofstream fout;
	fout.open(file);
	if (fout.fail()){
		std::cout << file << " не удалось открыть файл\n";
		return;
	}
	fout << std::setfill('-') << std::setw(129) << "\n" <<
	     "|Номер| Цена | Кол. |                 Процессор                    |              Видеокарта           | ОЗУ | Размер жесткого |\n" <<
             "|     |      |      |----------------------------------------------|-----------------------------------|     |                 |\n" << 
	     "|     |(Руб.)|(штук)|    Название    |        Тип        | Частота |        Название        | Объём Гб |  Гб |      (Гб)       |\n" <<
	             std::setw(129) << "\n"; 
	for (int i = 0; i < size; i++){
		fout << std::setfill(' ') <<
		   "|" << std::setw(5) << i + 1 << "|" << std::setw(6) <<SearchResult[i].CompCost << "|" 
		   << std::setw(6) << SearchResult[i].CompInStock << 
		     "|" << std::setw(16) << SearchResult[i].CompInfo.ProcName << "|" << std::setw(19) <<
		     SearchResult[i].CompInfo.ProcType << "|" << std::setw(9) << SearchResult[i].CompInfo.ClockSpeed << "|" 
		     << std::setw(24) << SearchResult[i].CompInfo.Graphics << "|" << std::setw(10) << SearchResult[i].CompInfo.GraphicVolume << "|" << std::setw(5) << 
		     SearchResult[i].CompInfo.RAM << "|" << std::setw(17) << SearchResult[i].CompInfo.Storage << "|\n";
		fout << std::setfill('-') << std::setw(129) << "\n"; 
	}
}

void SearchComp::showInfo(){
	std::cout << std::setfill('-') << std::setw(129) << "\n" <<
	     "|Номер| Цена | Кол. |                 Процессор                    |              Видеокарта           | ОЗУ | Размер жесткого |\n" <<
             "|     |      |      |----------------------------------------------|-----------------------------------|     |                 |\n" << 
	     "|     |(Руб.)|(штук)|    Название    |        Тип        | Частота |        Название        | Объём Гб |  Гб |      (Гб)       |\n" <<
	             std::setw(129) << "\n"; 
	for (int i = 0; i < size; i++){
		std::cout << std::setfill(' ') <<
		   "|" << std::setw(5) << i + 1 << "|" << std::setw(6) <<SearchResult[i].CompCost << "|" 
		   << std::setw(6) << SearchResult[i].CompInStock << 
		     "|" << std::setw(16) << SearchResult[i].CompInfo.ProcName << "|" << std::setw(19) <<
		     SearchResult[i].CompInfo.ProcType << "|" << std::setw(9) << SearchResult[i].CompInfo.ClockSpeed << "|" 
		     << std::setw(24) << SearchResult[i].CompInfo.Graphics << "|" << std::setw(10) << SearchResult[i].CompInfo.GraphicVolume << "|" << std::setw(5) << 
		     SearchResult[i].CompInfo.RAM << "|" << std::setw(17) << SearchResult[i].CompInfo.Storage << "|\n";
		std::cout << std::setfill('-') << std::setw(129) << "\n"; 
	}
}

void SearchComp::SortProcTypeAndClock(){
	std::cout << "Сортировка по типу процессора и частоте: \n";
	unsigned n = size;
	bool flag;
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (SearchResult[i].CompInfo.ProcType.compare(SearchResult[i - 1].CompInfo.ProcType) < 0)
			{
				swapElementsInMassive(i);
				flag = true;
			}
			else if (SearchResult[i].CompInfo.ProcType.compare(SearchResult[i - 1].CompInfo.ProcType) == 0 &&
				 SearchResult[i].CompInfo.ClockSpeed < SearchResult[i - 1].CompInfo.ClockSpeed)	
			{
				swapElementsInMassive(i);
				flag = true;
			}
		}
		n--;
	} while (flag);
	SearchComp::showInfo();
}

void SearchComp::SortRAM(){
	std::cout << "Сортировка по ОЗУ: \n";
	bool flag;
	unsigned n = size; 
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (SearchResult[i - 1].CompInfo.RAM> SearchResult[i].CompInfo.RAM){
				swapElementsInMassive(i);
				flag = true;
			}
		}
		n--;
	} while(flag);
	SearchComp::showInfo();
}
/* из четвертой лабы */
/*void SearchComp::SearchPrice() {
	if (size == 0)
	{
		std::cout << "Загрузите массив \n";
		return;
	}
	double BottomBorder, TopBorder;
	std::cout << "Введите нижнюю границу цены(нестрогое): ";
	std::cin >> BottomBorder;
	std::cout << "Введите верхнюю границу цены(нестрогое): ";
	std::cin >> TopBorder;
	std::vector<int> CollectIndexes; // Второй вариант со сбором индеков
	for (unsigned i = 0; i < CapabilitiesComp.size(); i++)
		if (BottomBorder <= CapabilitiesComp[i].CompCost && CapabilitiesComp[i].CompCost <= TopBorder)
			CollectIndexes.push_back(i);
	// Есть два варианта: 1) вектор собирающий индексы; 2) перераспределение памяти каждыый раз
	if (CollectIndexes.size() == 0)
	{
		std::cout << "Не найдено!\n";
		return;
	}
	SearchResult.clear();
	for(unsigned i = 0; i < CollectIndexes.size(); i++)
		SearchResult.insert(SearchResult.begin(), CapabilitiesComp[CollectIndexes[i]]);
	this -> SearchComp::SortProcTypeAndClock();
	char ch;
	std::cout << "Желаете сохранить результаты поиска в файл?(y/n)\n";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y')
		this -> OutputInFile();
}

void SearchComp::SearchHddVolume(){
	if (CapabilitiesComp.size() == 0)
	{
		std::cout << "Загрузите массив \n";
		return;
	}
	double BottomBorder, TopBorder;
	std::cout << "Введите нижнюю границу размера памяти(нестрогое): ";
	std::cin >> BottomBorder;
	std::cout << "Введите верхнюю границу размера памяти(нестрогое): ";
	std::cin >> TopBorder;
	std::vector<int> CollectIndexes; // Второй вариант со сбором индеков
	for (unsigned i = 0; i < CapabilitiesComp.size(); i++)
	{
		if (BottomBorder <= CapabilitiesComp[i].CompInfo.Storage && CapabilitiesComp[i].CompInfo.Storage <= TopBorder)
			CollectIndexes.push_back(i);
	}
	if (CollectIndexes.size() == 0)
	{
		std::cout << "Не найдено!\n";
		return;
	}
	SearchResult.clear();
	for(unsigned i = 0; i < CollectIndexes.size(); i++)
		SearchResult.insert(SearchResult.begin(), CapabilitiesComp[CollectIndexes[i]]);
	this -> SearchComp::SortRAM();
	char ch;
	std::cout << "Желаете сохранить результаты поиска в файл?(y/n)\n";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y')
		this -> OutputInFile();
}

void SearchComp::SearchBrandTypeRamETC(){
	if (CapabilitiesComp.size() == 0)
	{
		std::cout << "Загрузите массив \n";
		return;
	}
	std::string NameOfProc, TypeOfProc;
	double BottomBorder, TopBorder, BBRAM, TBRAM, BBVideo, TBVideo;
	std::cout << "Введите название марки процессора ";
	std::cin >> NameOfProc;
	std::cout << "Введите тип процессора ";
	std::cin >> TypeOfProc;
	std::cout << "Введите нижнюю границу размера памяти hdd(нестрогое): ";
	std::cin >> BottomBorder;
	std::cout << "Введите верхнюю границу размера памяти hdd(нестрогое): ";
	std::cin >> TopBorder;
	std::cout << "Введите нижнюю границу размера ОЗУ(нестрогое): ";
	std::cin >> BBRAM;
	std::cout << "Введите верхнюю границу размера ОЗУ(нестрогое): ";
	std::cin >> TBRAM;
	std::cout << "Введите нижнюю границу размера видеопамяти(нестрогое): ";
	std::cin >> BBVideo;
	std::cout << "Введите верхнюю границу размера видеопамяти(нестрогое): ";
	std::cin >> TBVideo;
	std::vector<int> CollectIndexes; // Второй вариант со сбором индеков
	for (unsigned i = 0; i < CapabilitiesComp.size(); i++)
		if (BottomBorder <= CapabilitiesComp[i].CompInfo.Storage && CapabilitiesComp[i].CompInfo.Storage <= TopBorder && 
			NameOfProc == CapabilitiesComp[i].CompInfo.ProcName && CapabilitiesComp[i].CompInfo.ProcType == TypeOfProc &&
		       	BBRAM <= CapabilitiesComp[i].CompInfo.RAM && CapabilitiesComp[i].CompInfo.RAM <= TBRAM &&
		      	BBVideo<= CapabilitiesComp[i].CompInfo.GraphicVolume && CapabilitiesComp[i].CompInfo.GraphicVolume <= TBVideo)
				CollectIndexes.push_back(i);
	if (CollectIndexes.size() == 0)
	{
		std::cout << "Не найдено!\n";
		return;
	}
	SearchResult.clear();
	for(unsigned i = 0; i < CollectIndexes.size(); i++)
		SearchResult.insert(SearchResult.begin(), CapabilitiesComp[CollectIndexes[i]]);
	this -> SearchComp::showInfo();
	char ch;
	std::cout << "Желаете сохранить результаты поиска в файл?(y/n)\n";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y')
		this -> OutputInFile();
}
*/

// вариант из 2 лабы

void SearchComp::SearchPrice(){
	if (CapabilitiesComp == NULL)
	{
		std::cout << "Загрузите массив \n";
		return;
	}
	double BottomBorder, TopBorder;
	std::cout << "Введите нижнюю границу цены(нестрогое): ";
	std::cin >> BottomBorder;
	std::cout << "Введите верхнюю границу цены(нестрогое): ";
	std::cin >> TopBorder;
//	SearchComp SearchResult;
	std::vector<int> CollectIndexes; // Второй вариант со сбором индеков
	for (int i = 0; i < workComputers::size; i++)
	{
		if (BottomBorder <= CapabilitiesComp[i].CompCost && CapabilitiesComp[i].CompCost <= TopBorder)
		{
			CollectIndexes.push_back(i);
	//		std::cout << "i= " << i << "\n";
		}	
	}
	// Есть два варианта: 1) вектор собирающий индексы; 2) перераспределение памяти каждыый раз

	if (CollectIndexes.size() == 0)
	{
		std::cout << "Не найдено!\n";
		return;
	}
	if (SearchResult != NULL)
		delete [] SearchResult;
	size = CollectIndexes.size();
	std::cout << size<< " size\n";
	SearchResult= new RECORD[size];
	for (int i = 0; i < size; i++)
		SearchResult[i] = CapabilitiesComp[CollectIndexes[i]];
	SearchComp::SortProcTypeAndClock();
	char ch;
	std::cout << "Желаете сохранить результаты поиска в файл?(y/n)\n";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y')
		SearchComp::OutputInFile();
}


void SearchComp::SearchHddVolume(){
	if (CapabilitiesComp == NULL)
	{
		std::cout << "Загрузите массив \n";
		return;
	}
	double BottomBorder, TopBorder;
	std::cout << "Введите нижнюю границу размера памяти(нестрогое): ";
	std::cin >> BottomBorder;
	std::cout << "Введите верхнюю границу размера памяти(нестрогое): ";
	std::cin >> TopBorder;
	std::vector<int> CollectIndexes; // Второй вариант со сбором индеков
	for (int i = 0; i < workComputers::size; i++)
	{
		if (BottomBorder <= CapabilitiesComp[i].CompInfo.Storage && CapabilitiesComp[i].CompInfo.Storage <= TopBorder)
			CollectIndexes.push_back(i);
	}
	if (CollectIndexes.size() == 0)
	{
		std::cout << "Не найдено!\n";
		return;
	}
	if (SearchResult != NULL)
		delete [] SearchResult;
	size = CollectIndexes.size();
	std::cout << size<< " size\n";
	SearchResult= new RECORD[size];

	for (int i = 0; i < size; i++)
		SearchResult[i] = CapabilitiesComp[CollectIndexes[i]];
	SearchComp::SortRAM();
	char ch;
	std::cout << "Желаете сохранить результаты поиска в файл?(y/n)\n";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y')
		SearchComp::OutputInFile();
}

void SearchComp::SearchBrandTypeRamETC(){
	if (CapabilitiesComp == NULL)
	{
		std::cout << "Загрузите массив \n";
		return;
	}
	std::string NameOfProc, TypeOfProc;
	double BottomBorder, TopBorder, BBRAM, TBRAM, BBVideo, TBVideo;
	std::cout << "Введите название марки процессора ";
	std::cin >> NameOfProc;
	std::cout << "Введите тип процессора ";
	std::cin >> TypeOfProc;
	std::cout << "Введите нижнюю границу размера памяти hdd(нестрогое): ";
	std::cin >> BottomBorder;
	std::cout << "Введите верхнюю границу размера памяти hdd(нестрогое): ";
	std::cin >> TopBorder;
	std::cout << "Введите нижнюю границу размера ОЗУ(нестрогое): ";
	std::cin >> BBRAM;
	std::cout << "Введите верхнюю границу размера ОЗУ(нестрогое): ";
	std::cin >> TBRAM;
	std::cout << "Введите нижнюю границу размера видеопамяти(нестрогое): ";
	std::cin >> BBVideo;
	std::cout << "Введите верхнюю границу размера видеопамяти(нестрогое): ";
	std::cin >> TBVideo;
	std::vector<int> CollectIndexes; // Второй вариант со сбором индеков
	for (int i = 0; i < size; i++)
	{
		if (BottomBorder <= CapabilitiesComp[i].CompInfo.Storage && CapabilitiesComp[i].CompInfo.Storage <= TopBorder && 
			NameOfProc == CapabilitiesComp[i].CompInfo.ProcName && CapabilitiesComp[i].CompInfo.ProcType == TypeOfProc &&
		       	BBRAM <= CapabilitiesComp[i].CompInfo.RAM && CapabilitiesComp[i].CompInfo.RAM <= TBRAM &&
		      	BBVideo<= CapabilitiesComp[i].CompInfo.GraphicVolume && CapabilitiesComp[i].CompInfo.GraphicVolume <= TBVideo)
				CollectIndexes.push_back(i);
	}
	if (CollectIndexes.size() == 0)
	{
		std::cout << "Не найдено!\n";
		return;
	}
	if (SearchResult != NULL)
		delete [] SearchResult;
	size = CollectIndexes.size();
	std::cout << size<< " size\n";
	SearchResult= new RECORD[size];

	for (int i = 0; i < size; i++)
		SearchResult[i] = CapabilitiesComp[CollectIndexes[i]];
	SearchComp::showInfo();
	char ch;
	std::cout << "Желаете сохранить результаты поиска в файл?(y/n)\n";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y')
		SearchComp::OutputInFile();
}
