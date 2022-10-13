int main()
{
	// Перший резистор - опір
	float resistances_1 = 34.0f;
	// Другий резистор - опір
	float resistances_2 = 23.0f;
	// Третій резистор - опір
	float resistances_3 = 41.0f;
	// Використовуючи формулу загального опору: r1*r2*r3/r1+r2+r3, визначаємо загальний опір
	float general_resistance = (resistances_1 * resistances_2 * resistances_3) / (float)(resistances_1 + resistances_2 + resistances_3);

	return 0;
}
