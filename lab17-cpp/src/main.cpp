#include "colleague.h"
#include "worker.h"

int main()
{

	const int N = 3;
	Colleague ** colleague = new Colleague*[N];
	colleague[0] = new Colleague(0, "Google", 3.6f, {"Ivan", "Teplyi", "dev-good@lal.com"}, confident);
	colleague[1] = new Colleague(1, "Microsoft", 2.0f, {"Ivan", "Teplyi", "dev-good@lal.com"}, confident);
	colleague[2] = new Colleague(0, "Google", 6.8f, {"Ivan", "Teplyi", "dev-good@lal.com"}, confident);

	Workers * workers = new Workers;
	for (size_t i = 0; i < N; ++i) {
		workers->addElement(i, colleague[i]);

	}
	size_t number_of_workers = workers->findCountColleagueInCompany_WithoutInsurance("Google");
	printf("Worker without insurance in company %s: %zu\n", "Google", number_of_workers);
	workers->sort("work_experience");
	workers->print();

	for (size_t i = 0; i < N; ++i) {
		delete colleague[i];
	}
	delete workers;
	delete[] colleague;

	return 0;
}