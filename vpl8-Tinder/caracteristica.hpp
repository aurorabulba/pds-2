#ifndef CARACTERISTICA_H
#define CARACTERISTICA_H

class CaractFis {
  //Valores validos:
  //sexo: M: Masculino, F: Feminino
  //pele: M:Morena, L:Loira, R:Ruiva
  //tipoFisico: M:Magro,E:Esbelto,O:Obeso
  public:
    char sexo, pele, tipoFisico;
    CaractFis(char sex, char pel, char tpf);
    CaractFis() = default;
};

#endif