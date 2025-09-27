#include <bits/stdc++.h>
using namespace std;

struct Huesped {
    string nombre;
    int ciudad;   // 0: BsAs, 1: Rosario, 2: Mendoza
    int dias;
    double importe;
    int tipo;     // 0: pensión completa, 1: media pensión, 2: sólo desayuno, 3: sólo habitación
};

int main() {
    int n;
    cout << "Cantidad de huespedes: ";
    if(!(cin >> n)) return 0;
    vector<Huesped> v(n);
    for(int i=0;i<n;i++){
        cout << "Huesped " << i+1 << " nombre ciudad(0/1/2) dias importe tipo(0..3):\n";
        cin >> ws;
        getline(cin, v[i].nombre);
        cin >> v[i].ciudad >> v[i].dias >> v[i].importe >> v[i].tipo;
    }

    // a) porcentaje de huéspedes de cada ciudad
    vector<int> cuentaCiudad(3,0);
    for(auto &h: v) if(h.ciudad>=0 && h.ciudad<3) cuentaCiudad[h.ciudad]++;
    cout << "\nPorcentajes por ciudad:\n";
    for(int c=0;c<3;c++){
        double pct = n ? (100.0 * cuentaCiudad[c] / n) : 0.0;
        cout << c << ": " << pct << "% (" << cuentaCiudad[c] << ")\n";
    }

    // b) nombre del huesped que mayor importe haya pagado y sea de Rosario (ciudad==1)
    double maxImporte = -1.0;
    string nombreMax = "(ninguno)";
    for(auto &h : v){
        if(h.ciudad == 1 && h.importe > maxImporte) {
            maxImporte = h.importe;
            nombreMax = h.nombre;
        }
    }
    cout << "\nMayor importe pagado por huésped de Rosario: " << nombreMax << " ($" << maxImporte << ")\n";

    // c) matriz de conteo 3x4
    int mat[3][4] = {}; // inicializa a 0
    for(auto &h: v){
        if(h.ciudad>=0 && h.ciudad<3 && h.tipo>=0 && h.tipo<4)
            mat[h.ciudad][h.tipo]++;
    }
    cout << "\nMatriz 3x4 (filas: ciudades 0..2, columnas: tipo 0..3):\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++) cout << mat[i][j] << " ";
        cout << "\n";
    }

    // d) importe total por pension completa (tipo 0)
    double totalPensionCompleta = 0.0;
    for(auto &h: v) if(h.tipo==0) totalPensionCompleta += h.importe;
    cout << "\nImporte total por pensión completa: $" << totalPensionCompleta << "\n";

    return 0;
}
