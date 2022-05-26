#include <iostream>
using namespace std;
class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	void add(int reserved);
	void cancel(int reserved);
	void exit();
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	double percent = 0;
	if (reserved >= capacity) {
		percent = 100;
		cout << percent<<"% seats are ocupied\n";
	}
	else {
		percent = 100.0 * ((double)this->reserved / this->capacity);
		cout<< "Flight seats taken "<< " id " << this->id << " reserved " << this->reserved << " capacity " << this->capacity << " percentage " << percent << endl;
	}
	// print report here
}
void FlightBooking::add(int reserved) {
	if (this->reserved + reserved > capacity) {
		reserved = 0;
		cout << "this operation is impossible\n";
	}
	else {
		this->reserved += reserved;
		cout << "successfully added!\n";
	}
}
void FlightBooking::cancel(int reserved) {
	if (this->reserved - reserved > 0) {
		this->reserved = this->reserved - reserved;
		cout << "successfully canceled reservation\n";
	}
	else {
		reserved = 0;
		cout << "this operation is impossible\n";
	}
}
void FlightBooking::exit() {
	cout << "thank for choosing out booking company\n";
	cout << "booking has finished\n";
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{	
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
	if (this->reserved >= this->capacity) 
	{
		cout << "all seats are ocupied\n";
	}
	// Save data to members
}
int main() {
	int reserved = 0,
		capacity = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	booking.add(20);
	booking.printStatus();
	booking.cancel(60);
	booking.printStatus();
	booking.exit();
	return 0;
}