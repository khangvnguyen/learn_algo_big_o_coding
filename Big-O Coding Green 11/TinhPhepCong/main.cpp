#include <iostream>
using namespace std;

int main() {
	int thang_truoc;
	int thang_nay;
	cin >> thang_truoc >> thang_nay;
	int sd;
	sd = thang_nay - thang_truoc;

	double tien_sd;
	if(sd <= 50){
		tien_sd = 1484*sd;
	} else if (sd <= 100) {
		tien_sd = 74200+1533*(sd-50);
	} else if (sd <= 200){
		tien_sd = 150850+1786*(sd-100);
	} else if (sd <= 300){
		tien_sd = 329450+2242*(sd-200);
	} else if (sd <= 400){
		tien_sd = 553650+2503*(sd-300);
	} else {
		tien_sd = 803950+2587*(sd-400);
	}
	
	double vat;
	vat = 0.10*tien_sd;

	int tien_phai_tra;
	tien_phai_tra = tien_sd + vat;

	cout << tien_phai_tra;
}
