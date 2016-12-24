//#include <cstdio>
//#include <cstdlib>
//
//#define M 902
//#define M2 9900
//
//int main() {
//	int n, m;
//	int vec[M];		// retine codurile celor m incaperi, pentru fiecare jucator
//	bool visit[M];	// retine care incaperi au fost vizitate de jucatorul curent
//	int elim[M];	// retine etapa la care a fost eliminat un anumit jucator, pentru toti cei eliminati
//	int castigator, incapere, etapa, eliminati; // rezultate
//	int incapere_c, etapa_c, cod_c;
//
//	freopen("joc10.in", "r", stdin);
//	freopen("joc10.out", "w", stdout);
//
//	scanf("%d %d", &n, &m);
//
//	castigator = 0; incapere = 0; etapa = M2; eliminati = 0;
//	for (int jucator_id = 1; jucator_id <= n; ++jucator_id) {
//		elim[jucator_id] = M2;
//		for (int i = 1; i <= m; ++i) {
//			scanf("%d", &vec[i]);
//			visit[i] = false;
//		}
//		visit[1] = true;
//		incapere_c = 1;
//		etapa_c = 1;
//		cod_c = vec[1];
//		while (cod_c != 0 && cod_c != 9999) {
//			etapa_c += cod_c % 10 + 1;
//			incapere_c = cod_c / 10;
//			if (visit[incapere_c] == false) {
//				visit[incapere_c] = true;
//			}
//			else {
//				break;
//			}
//			cod_c = vec[incapere_c];
//		}
//		if (cod_c == 0) {
//			elim[jucator_id] = etapa_c;
//		}
//		else if (cod_c == 9999 && etapa_c < etapa) {
//			castigator = jucator_id;
//			incapere = incapere_c;
//			etapa = etapa_c;
//		}
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (elim[i] <= etapa) {
//			++eliminati;
//		}
//	}
//
//	printf("%d %d %d %d\n", castigator, incapere, etapa, eliminati);
//
//	return 0;
//}
