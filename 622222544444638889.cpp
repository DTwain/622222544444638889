#include <iostream>
#include <iomanip>
typedef long double ld;
ld cons_matematica = 2.718281828459045;
int main() {
	ld nr = 0;
	std::cin >> nr;
	int put_10 = 1;
	ld rez = 0;
	ld cnr = nr;
	while ((ld)cnr / cons_matematica > 0.98) {
		rez++;
		cnr = (ld)cnr / cons_matematica;
	}
	ld nr_formal = (ld)std::pow(cons_matematica, rez);
	for (int i = 1; i <= 6; i++) {
		ld dif_minima = 2147483647;
		ld numar_e_la_put = 1;
		ld put_care_trebuie_sa_o_adun = 0;
		for (int j = 0; j < 9; j++) {
			ld put = (ld)(j * (ld)1 / (ld)std::pow(10, put_10));
			ld nr_nou = (ld)nr_formal * (ld)std::pow(cons_matematica, put);

			ld put_pt_2 = (ld)((j + 1) * (ld)1 / (ld)std::pow(10, put_10));
			ld nr_local2 = (ld)nr_formal * (ld)std::pow(cons_matematica, put_pt_2);
			if (nr_nou < nr && nr_local2 < nr) {
				ld dif_1, dif_2;
				dif_1 = nr - nr_nou;
				dif_2 = nr - nr_local2;
				if (dif_1 <= dif_2 && nr_nou <= nr) dif_minima = dif_1, put_care_trebuie_sa_o_adun = put;
				else if (dif_1 >= dif_2 && nr_local2 <= nr) dif_minima = dif_2, put_care_trebuie_sa_o_adun = put_pt_2;
			}
		}
		put_10 += 1;
		nr_formal *= (ld)std::pow(cons_matematica, put_care_trebuie_sa_o_adun);
		rez += put_care_trebuie_sa_o_adun;
	}
	std::cout << std::fixed << std::setprecision(9) << rez;
	return 0;
}