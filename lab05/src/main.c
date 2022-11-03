int main()
{
	int number = 34;//дане нам число
	int quantity = 0;//кількість купюр що знадобиться
	int sum = 0;//сума для підрахунку
	int nominal_money1 = 10;//перша купюра
	int nominal_money2 = 5;//друга купюра
	int nominal_money3 = 2;//третя купюра
	int nominal_money4 = 1;//четверта купюра
	while (sum < number) {//виконується до моменту поки сума не бульша за дане число
		if (sum + nominal_money1 <= number) {//якщо поточна сума більша за дане число, то
			sum += nominal_money1;//до суми додати ноиінал першого числа 
			quantity++;//та збільшити кільквсть на 1
		} else if (sum + nominal_money2 <= number) {//якщо поточна сума більша за дане число, то
			sum += nominal_money2;//до суми додати номінал другого числа
			quantity++;//та збільшити кільквсть на 1
		} else if (sum + nominal_money3 <= number) {//якщо поточна сума більша за дане число, то
			sum += nominal_money3;//до суми додати номінал третього числа
			quantity++;//та збільшити кільквсть на 1
		} else if (sum + nominal_money4 <= number) {//якщо поточна сума більша за дане число, то
			sum += nominal_money4;//до суми додати номінал четвертого числа
			quantity++;//та збільшити кільквсть на 1
		}
	}
	return 0;
}
