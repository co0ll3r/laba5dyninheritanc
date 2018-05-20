#include "CompHeader.h"

// Должно копироваться три перечня!
//
void swap(Perechen& first, Perechen& second){
	std::swap(first.pBrandlen, second.pBrandlen);
	std::swap(first.pProclen, second.pProclen);
	std::swap(first.pVideolen, second.pVideolen);
	std::swap(first.perechenBrands, second.perechenBrands);
	std::swap(first.perechenProcTypes, second.perechenProcTypes);
	std::swap(first.perechenVideocardVolume, second.perechenVideocardVolume);
}

Perechen::Perechen(const Perechen& copy) : Perechen(copy.pBrandlen, copy.pProclen, copy.pVideolen)  {
	std::copy(copy.perechenBrands, copy.perechenBrands + pBrandlen, perechenBrands);
	std::copy(copy.perechenProcTypes, copy.perechenProcTypes + pProclen, perechenProcTypes);
	std::copy(copy.perechenVideocardVolume, copy.perechenVideocardVolume + pVideolen, perechenVideocardVolume);
}

Perechen& Perechen::operator=(Perechen copy){
	if(&copy != this)
		swap(*this, copy);
	return *this;
}

void Perechen::testCopyOperator(){
	Perechen eg;
	std::cout << "введите первый массив:\n";
	eg.InputFromFile();
	eg.workComputers::showInfo();
	makePerechen1(eg, eg);
	makePerechen2(eg, eg);
	makePerechen3(eg, eg);
	eg.showFirstPerech();
	eg.showSecondPerech();
	eg.showThirdPerech();
	if (true){
		Perechen eg2;
		std::cout << "введите второй массив:\n";
		eg2.InputFromFile();
		eg2.workComputers::showInfo();
		makePerechen1(eg2, eg2);
		makePerechen2(eg2, eg2);
		makePerechen3(eg2, eg2);
		eg = eg2;
	}
	std::cout << "очистка второго массива\n";
	eg.showFirstPerech();
	eg.showSecondPerech();
	eg.showThirdPerech();
}

void Perechen::testCopyConstructor(){
	workComputers some;
	Perechen eg;
	std::cout << "введите первый массив:\n";
	some.InputFromFile();
	makePerechen1(some, eg);
	makePerechen2(some, eg);
	makePerechen3(some, eg);
	eg.showFirstPerech();
	eg.showSecondPerech();
	eg.showThirdPerech();
	Perechen eg2(eg);
	//eg.Perechen::~Perechen();
	std::cout << "первый массив удален\n";
	eg2.showFirstPerech();
	eg2.showSecondPerech();
	eg2.showThirdPerech();
}

void Perechen::showFirstPerech(){
	std::cout << std::setfill('-') << std::setw(57) << '\n' <<
		"|     Название процессора     | Количество компьютеров |\n" << 
		std::setw(57) << '\n';
	std::cout << std::setfill(' ');
//	std::cout << pBrandlen << '\n';
	for (int i = 0; i < pBrandlen; i++)
		std::cout << '|' << std::setw(29) << perechenBrands[i].ProcName << '|' << std::setw(24) << perechenBrands[i].Count << "|\n";
	std::cout << '\n';
}

void Perechen::showSecondPerech(){
	std::cout << std::setfill('-') << std::setw(52) << '\n' <<
		"|     Тип процессора     | Количество компьютеров |\n" << 
		std::setw(52) << '\n';
	std::cout << std::setfill(' ');
	for (int i = 0; i < pProclen; i++)
		std::cout << '|' << std::setw(24) << perechenProcTypes[i].ProcType<< '|' << std::setw(24) << perechenProcTypes[i].Count << "|\n";
	std::cout << '\n';
}

void Perechen::showThirdPerech(){
	std::cout << std::setfill('-') << std::setw(55) << '\n' <<
		"|     Объём видеопамяти     | Количество компьютеров |\n" << 
		std::setw(55) << '\n';
	std::cout << std::setfill(' ');
	for (int i = 0; i < pVideolen; i++)
		std::cout << '|' << std::setw(27) << perechenVideocardVolume[i].GraphicVolume << '|' << std::setw(24) << perechenVideocardVolume[i].Count << "|\n";
	std::cout << '\n';
}

/*template <class PerechenTemplate>
void swapElementsInPerechen(int index, PerechenTemplate CL){
	PerechenTemplate temp = CL; 
	CL[index] = CL[index - 1];
       	CL[index - 1] = temp;	
}*/

void Perechen::sortProcTypeFirstPerech(){
//	std::cout << "Сортировака перечня по названию процессора \n";
	int n = pBrandlen;
	bool flag;
	do{
		flag = false;
		for (int i = 1; i < n; i++){
			//			swapElementsInPerechen(i, *this ->perechenBrands);
			if (perechenBrands[i - 1].ProcName > perechenBrands[i].ProcName)
			{
				BrandPerech temp = perechenBrands[i];
				perechenBrands[i] = perechenBrands[i - 1];
				perechenBrands[i - 1] = temp;
				flag = true;
			}
		}
		n--;
	} while (flag);	
//	showFirstPerech();
}

void Perechen::sortCountSecondPerech(){
//	std::cout << "Сортировка перечня по количеству компьютеров с данным процессором\n";
	int n = pProclen;
	bool flag;
	do{
		flag = false;
		for(int i = 1; i < n; i++){
			if (perechenProcTypes[i - 1].Count > perechenProcTypes[i].Count)			
			{
				TypeProcPerech temp = perechenProcTypes[i];
				perechenProcTypes[i] = perechenProcTypes[i - 1];
				perechenProcTypes[i - 1] = temp;
				flag = true;
			}
		}
		n--;
	} while (flag);
//	showSecondPerech();
}

void Perechen::sortVideoVolumeThirdPerech(){
//	std::cout << "Сортировака перечня по объему видеопамяти\n";
	int n = pVideolen;
	bool flag;
	do{
		flag = false;
		for (int i = 1; i < n; i++){
			if (perechenVideocardVolume[i - 1].GraphicVolume > perechenVideocardVolume[i].GraphicVolume)
			{
				VideocardsPerech temp = perechenVideocardVolume[i];

				perechenVideocardVolume[i] = perechenVideocardVolume[i - 1];
				perechenVideocardVolume[i - 1] = temp;
				flag = true;
			}
		}
		n--;
	} while (flag);	
//	showThirdPerech();
}

void Perechen::saveFirstPerech(){
	std::string file;
	std::cout << "Введите имя файла для сохранения 1 перечень\n";
	std::cin >> file;
	std::ofstream fout;
	fout.open(file);
	if (fout.fail()){
		std::cout << file << " не удалось открыть файл\n";
		return;
	}
	fout <<   std::setfill('-') << std::setw(57) << '\n' <<
		"|     Название процессора     | Количество компьютеров |\n" << 
	std::setw(57) << '\n';
	fout << std::setfill(' ');
//	std::cout << pBrandlen << '\n';
	for (int i = 0; i < pBrandlen; i++)
		fout << '|' << std::setw(29) << perechenBrands[i].ProcName << '|' << std::setw(24) << perechenBrands[i].Count << "|\n";
	fout << '\n';
}

void Perechen::saveSecondPerech(){
	std::string file;
	std::cout << "Введите имя файла для сохранения 2 перечень\n";
	std::cin >> file;
	std::ofstream fout;
	fout.open(file);
	if (fout.fail()){
		std::cout << file << " не удалось открыть файл\n";
		return;
	}
	fout << std::setfill('-') << std::setw(52) << '\n' <<
		"|     Тип процессора     | Количество компьютеров |\n" << 
		std::setw(52) << '\n';
	fout << std::setfill(' ');
	for (int i = 0; i < pProclen; i++)
		fout << '|' << std::setw(24) << perechenProcTypes[i].ProcType<< '|' << std::setw(24) << perechenProcTypes[i].Count << "|\n";
	fout << '\n';
}

void Perechen::saveThirdPerech(){
	std::string file;
	std::cout << "Введите имя файла для сохранения 3 перечень\n";
	std::cin >> file;
	std::ofstream fout;
	fout.open(file);
	if (fout.fail()){
		std::cout << file << " не удалось открыть файл\n";
		return;
	}
	fout << std::setfill('-') << std::setw(55) << '\n' <<
		"|     Объём видеопамяти     | Количество компьютеров |\n" << 
		std::setw(55) << '\n';
	fout << std::setfill(' ');
	for (int i = 0; i < pVideolen; i++)
		fout << '|' << std::setw(27) << perechenVideocardVolume[i].GraphicVolume << '|' << std::setw(24) << perechenVideocardVolume[i].Count << "|\n";
	fout << '\n';
}

void makePerechen1(workComputers clWorkComp, Perechen& clPerech){
	if (clWorkComp.size == 0){
		std::cout << "Ошибка при создании 1 перечня! Введите массив\n";
		return;
	}
	std::set<std::string> UniqueNames;
	for (int i = 0; i < clWorkComp.size; i++)
		UniqueNames.insert(clWorkComp.CapabilitiesComp[i].CompInfo.ProcName);
	int nomerMass = 0, counter = 1;
	clPerech.pBrandlen = UniqueNames.size(); 
	if (clPerech.perechenBrands != NULL)
		delete [] clPerech.perechenBrands;
	clPerech.perechenBrands = new BrandPerech[clPerech.pBrandlen];
	for (auto a : UniqueNames)
	{
		clPerech.perechenBrands[nomerMass].ProcName = a;
		for (int i = 0; i < clWorkComp.size; i++)
			if (a == clWorkComp.CapabilitiesComp[i].CompInfo.ProcName)
				clPerech.perechenBrands[nomerMass].Count = counter++;
		counter = 1;
		nomerMass++;
	}	
}

void makePerechen2(workComputers clWorkComp, Perechen& clPerech){
	if (clWorkComp.size == 0){
		std::cout << "Ошибка при создании 2 перечня! Введите массив\n";
		return;
	}
	std::set<std::string> UniqueNames;
	int nomerMass = 0, counter = 1;
	for (int i = 0; i < clWorkComp.size; i++)
		UniqueNames.insert(clWorkComp.CapabilitiesComp[i].CompInfo.ProcType);
	clPerech.pProclen = UniqueNames.size();
	if (clPerech.perechenProcTypes != NULL)
		delete [] clPerech.perechenProcTypes;
	clPerech.perechenProcTypes = new TypeProcPerech[clPerech.pProclen];
	for (auto a : UniqueNames)
	{
		clPerech.perechenProcTypes[nomerMass].ProcType = a;
		for (int i = 0; i < clWorkComp.size; i++)
			if (a == clWorkComp.CapabilitiesComp[i].CompInfo.ProcType)
				clPerech.perechenProcTypes[nomerMass].Count = counter++;
		counter = 1;
		nomerMass++;
	}
}

void makePerechen3(workComputers clWorkComp, Perechen& clPerech){
	if (clWorkComp.size == 0){
		std::cout << "Ошибка при создании 3 перечня! Введите массив\n";
		return;
	}
	std::set<double> VolumePer;
 	int nomerMass = 0, counter = 1;
	for (int i = 0; i < clWorkComp.size; i++)
		VolumePer.insert(clWorkComp.CapabilitiesComp[i].CompInfo.GraphicVolume);
	clPerech.pVideolen = VolumePer.size();
	if (clPerech.perechenVideocardVolume != NULL)
		delete [] clPerech.perechenVideocardVolume;
	clPerech.perechenVideocardVolume = new VideocardsPerech[clPerech.pVideolen];
	for (auto a : VolumePer){
		clPerech.perechenVideocardVolume[nomerMass].GraphicVolume = a;
		for (int i = 0; i < clWorkComp.size; i++)
			if (a == clWorkComp.CapabilitiesComp[i].CompInfo.GraphicVolume)
				clPerech.perechenVideocardVolume[nomerMass].Count = counter++;
		counter = 1;
		nomerMass++;
	}
}
