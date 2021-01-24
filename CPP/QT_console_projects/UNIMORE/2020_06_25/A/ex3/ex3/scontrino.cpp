#include <string>
#include <vector>
#include <utility>      // std::pair, std::make_pair

using namespace std;

class Scontrino {


	public:
		Scontrino(string n, string d, string o) {
			this->nome = n;
			this->dataspesa = d;
			this->orario = o;
		}
		string stampa() { 
			string result = "Negozio " + this->nome + "\n";
			result = result + "Data " + this->dataspesa + " Ora " + this->orario + "\n";
			result = result + "===========================\nLista voci\n\n";
			for (auto x : voci) {
				result = result + "  " + x.first + ":" + to_string(x.second) + "\n";
			}
			return result;
		} 
		
		void addVoce(string desc, float costo) {
			pair<string, float> p {desc, costo};
			this->voci.push_back(p);
		}
		float getTotale() {
			float t = 0;
			for (auto x : voci) {
				t = t + x.second;
			}
			return t;
		}

	private:
		string nome;
		string dataspesa;
		string orario;
		vector<pair<string, float>> voci;

};

