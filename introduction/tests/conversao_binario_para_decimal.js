const exemplos = ["00100110"];

const resultado = exemplos.map((exemplo) => {
  const reverso = exemplo.split("").reverse().join("");
  let acumulador = 0;

  for (let i = 0; i < reverso.length; i++) {
    if (Number(reverso[i])) {
      acumulador += 2 ** i;
    }
  }
  return acumulador;
});

console.log(resultado);
