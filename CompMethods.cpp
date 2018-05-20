#include "CompHeader.h"

void swap(workComputers& first, workComputers& second){
	std::swap(first.size, second.size);
	std::swap(first.CapabilitiesComp, second.CapabilitiesComp);
}
workComputers::workComputers(const workComputers& copy) : workComputers(copy.size){
//		 size(copy.size), CapabilitiesComp(size ? new RECORD[size] : nullptr) {
	std::copy(copy.CapabilitiesComp, copy.CapabilitiesComp + size, CapabilitiesComp);
}

workComputers& workComputers::operator=(workComputers copy){
	if(&copy != this)
		swap(*this, copy);
	return *this;
}
//size(copy.size), CapabilitiesComp(size ? new RECORD[size] : nullptr){

void workComputers::testCopyOperator(){
	workComputers eg;
	std::cout << "введите первый массив:\n";
	eg.InputFromFile();
	eg.showInfo();
	if (true){
		workComputers eg2;
		std::cout << "введите второй массив:\n";
		eg2.InputFromFile();
		eg2.showInfo();
		eg = eg2;
	}
	std::cout << "очистка второго массива\n";
	eg.showInfo();
}

void workComputers::testCopyConstructor(){
	workComputers eg;
	std::cout << "введите первый массив:\n";
	eg.InputFromFile();
	eg.showInfo();
	workComputers eg2(eg);
	std::cout << "первый массив удален\n";
	eg2.showInfo();
}

void workComputers::InputFromFile(){
	std::string file;
	std::cout << "Введите имя файла для чтения\n";
	std::cin >> file;
	std::ifstream fin;
	fin.open(file);
	if (fin.fail()){
		std::cout << file << " не удалось создать файл\n";
		return;
	}
	RECORD ab;	
	RECORD* CopyCapComp;
	int i = -1;
	char end = '1';
	while(end != '\0'){
		if (fin.fail()) 
			break;
		i++;
		fin >> ab.CompCost >> ab.CompInStock >>
			ab.CompInfo.ProcName >> ab.CompInfo.ProcType  >>  
			ab.CompInfo.ClockSpeed >> ab.CompInfo.Graphics >>
			ab.CompInfo.GraphicVolume >>
			ab.CompInfo.RAM >> ab.CompInfo.Storage >> end;

		CopyCapComp = new RECORD[i + 1];
		for (int j = 0; j < i; j++)
			if (CapabilitiesComp != NULL)
				CopyCapComp[j] = CapabilitiesComp[j];
		CopyCapComp[i] = ab;
		if (CapabilitiesComp != NULL)
			delete [] CapabilitiesComp;
		CapabilitiesComp = CopyCapComp;
		CopyCapComp = NULL;
	}
	size = ++i;
}

void workComputers::OutputInFile(){
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
		   "|" << std::setw(5) << i + 1 << "|" << std::setw(6) <<CapabilitiesComp[i].CompCost << "|" 
		   << std::setw(6) << CapabilitiesComp[i].CompInStock << 
		     "|" << std::setw(16) << CapabilitiesComp[i].CompInfo.ProcName << "|" << std::setw(19) <<
		     CapabilitiesComp[i].CompInfo.ProcType << "|" << std::setw(9) << CapabilitiesComp[i].CompInfo.ClockSpeed << "|" 
		     << std::setw(24) << CapabilitiesComp[i].CompInfo.Graphics << "|" << std::setw(10) << CapabilitiesComp[i].CompInfo.GraphicVolume << "|" << std::setw(5) << 
		     CapabilitiesComp[i].CompInfo.RAM << "|" << std::setw(17) << CapabilitiesComp[i].CompInfo.Storage << "|\n";
		fout << std::setfill('-') << std::setw(129) << "\n"; 
	}
}

void workComputers::Add_comp(){
	RECORD add;
	std::cout << "Введите марку процессора: ";
	std::cin >> add.CompInfo.ProcName;
	std::cout << "Введите тип процессора(хар-ки): ";
	std::cin >> add.CompInfo.ProcType; 
	std::cout << "Введите частоту процессора: ";
	std::cin >> add.CompInfo.ClockSpeed; 
	std::cout << "Введите название видеокарты: ";
	std::cin >> add.CompInfo.Graphics;
	std::cout << "Введите объем видеокарты: ";
	std::cin >> add.CompInfo.GraphicVolume;
	std::cout << "Введите объем ОЗУ: ";
	std::cin >> add.CompInfo.RAM; 
	std::cout << "Введите объем жесткого диска: "; 
	std::cin >> add.CompInfo.Storage; 
	std::cout << "Введите цену: ";
	std::cin >> add.CompCost;
	std::cout << "Введите количество компьютеров на складе: ";
	std::cin >> add.CompInStock;
	RECORD* CopyCapComp = new RECORD[size + 1];
	if (CopyCapComp == NULL)
	{
		std::cout << "Ошибка выделения памяти при добавлении компьютера!\n";
		exit(-1);
	}
	for (int j = 0; j < size; j++)
		if (CapabilitiesComp != NULL)
			CopyCapComp[j] = CapabilitiesComp[j];
	CopyCapComp[size] = add;
	if (CapabilitiesComp != NULL)
		delete [] CapabilitiesComp;
	CapabilitiesComp = CopyCapComp;
	size++;
	CopyCapComp = NULL;

}

void workComputers::Delete_comp(){
	if (CapabilitiesComp == NULL)
	{
		std::cout << "Загрузите данные(массив элементов), т.к. массив пуст";
		return;	
	}
	int n;
	char ch;
	workComputers::showInfo();
	std::cout << "Введите номер строки для удаления: ";
	std::cin >> n;
	if (n < 1 || n > size){
		std::cout << " нет такой строки\n";
		return;
	}
	n--;
	std::cout << " удалить строку(press y):";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y'){
		RECORD* CopyCapComp = new RECORD[size - 1];
		int i, j;
		for (i = 0; i < n; i++)
			CopyCapComp[i] = CapabilitiesComp[i];
		for (i = n + 1, j = n; i < size; i++, j++)
			CopyCapComp[j] = CapabilitiesComp[i];
		if (CapabilitiesComp != NULL)
			delete [] CapabilitiesComp;
		CapabilitiesComp = CopyCapComp;
		CopyCapComp = NULL;
		size--;
	}
}

void workComputers::showInfo(){
	std::cout << std::setfill('-') << std::setw(129) << "\n" <<
	     "|Номер| Цена | Кол. |                 Процессор                    |              Видеокарта           | ОЗУ | Размер жесткого |\n" <<
             "|     |      |      |----------------------------------------------|-----------------------------------|     |                 |\n" << 
	     "|     |(Руб.)|(штук)|    Название    |        Тип        | Частота |        Название        | Объём Гб |  Гб |      (Гб)       |\n" <<
	             std::setw(129) << "\n"; 
	for (int i = 0; i < size; i++){
		std::cout << std::setfill(' ') <<
		   "|" << std::setw(5) << i + 1 << "|" << std::setw(6) <<CapabilitiesComp[i].CompCost << "|" 
		   << std::setw(6) << CapabilitiesComp[i].CompInStock << 
		     "|" << std::setw(16) << CapabilitiesComp[i].CompInfo.ProcName << "|" << std::setw(19) <<
		     CapabilitiesComp[i].CompInfo.ProcType << "|" << std::setw(9) << CapabilitiesComp[i].CompInfo.ClockSpeed << "|" 
		     << std::setw(24) << CapabilitiesComp[i].CompInfo.Graphics << "|" << std::setw(10) << CapabilitiesComp[i].CompInfo.GraphicVolume << "|" << std::setw(5) << 
		     CapabilitiesComp[i].CompInfo.RAM << "|" << std::setw(17) << CapabilitiesComp[i].CompInfo.Storage << "|\n";
		std::cout << std::setfill('-') << std::setw(129) << "\n"; 
	}
}

void workComputers::swapElementsInMassive(unsigned index){
	RECORD temp = CapabilitiesComp[index];
	CapabilitiesComp[index] = CapabilitiesComp[index - 1];
	CapabilitiesComp[index - 1] = temp;
}

void workComputers::SortProcTypeAndClock(){
	std::cout << "Сортировка по типу процессора и частоте: \n";
	unsigned n = size; 
	bool flag;
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i].CompInfo.ProcType.compare(CapabilitiesComp[i - 1].CompInfo.ProcType) < 0)
			{
				swapElementsInMassive(i);
				flag = true;
			}
			else if (CapabilitiesComp[i].CompInfo.ProcType.compare(CapabilitiesComp[i - 1].CompInfo.ProcType) == 0 &&
				 CapabilitiesComp[i].CompInfo.ClockSpeed < CapabilitiesComp[i - 1].CompInfo.ClockSpeed)	
			{
				swapElementsInMassive(i);
				flag = true;
			}
		}
		n--;
	} while (flag);
	workComputers::showInfo();
}

void workComputers::SortProcName(){
	std::cout << "Сортировка по названию процессора: \n";
	unsigned n = size; 
	bool flag;
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i].CompInfo.ProcName.compare(CapabilitiesComp[i - 1].CompInfo.ProcName) < 0)
			{
				swapElementsInMassive(i);
				flag = true;
			}
			else if (CapabilitiesComp[i].CompInfo.ProcName.compare(CapabilitiesComp[i - 1].CompInfo.ProcName) == 0 &&
					CapabilitiesComp[i].CompInfo.ProcType.compare(CapabilitiesComp[i - 1].CompInfo.ProcType) < 0)
			{
				swapElementsInMassive(i);
				flag = true;
			}
		}
		n--;
	} while (flag);
	workComputers::showInfo();
}

void workComputers::SortPrice(){
	std::cout << "Сортировка по цене: \n";
	bool flag;
	unsigned n = size; 
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i - 1].CompCost > CapabilitiesComp[i].CompCost){
				swapElementsInMassive(i);
				flag = true;
			}
		}
		n--;
	} while(flag);
	workComputers::showInfo();
}
