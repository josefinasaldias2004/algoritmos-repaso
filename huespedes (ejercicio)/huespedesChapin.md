[ DECLARAR ]
  arreglo H[1..n] de Huesped
  entero mat[0..2][0..3] <- 0
  entero cuenta[0..2] <- 0
  real totalPension <- 0

[ PROCESO ]
  Leer n
  Para i <- 1 hasta n
    Leer H[i].nombre, H[i].ciudad, H[i].dias, H[i].importe, H[i].tipo
    cuenta[H[i].ciudad] <- cuenta[H[i].ciudad] + 1
    mat[H[i].ciudad][H[i].tipo] <- mat[H[i].ciudad][H[i].tipo] + 1
    Si H[i].tipo = 0 Entonces
      totalPension <- totalPension + H[i].importe
    FinSi
  FinPara

  // b) buscar mayor importe en ciudad=1 (Rosario)
  real max <- -1
  cadena nombreMax <- ""
  Para i <- 1 hasta n
    Si H[i].ciudad = 1 y H[i].importe > max Entonces
      max <- H[i].importe
      nombreMax <- H[i].nombre
    FinSi
  FinPara
