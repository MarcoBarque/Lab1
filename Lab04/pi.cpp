#include <iostream>
#include <omp.h>
#include <sys/time.h>

//Funcion para tener los segundos del momento
double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;

  return sec;
}


int main(int argc, char* argv[]){

  // Número de iteraciones se lee como entrada de la aplicación
  // Se desea que el número de argumentos sean dos:
  // El nombre del programa y el número de iteraciones
  if(argc != 3){
    std::cerr << "Usage: " << argv[0] << " --n [iterations]" << std::endl;
    exit(1);
  }
  // Ahora leemos el número de iteraciones
  int n;
  n = atoi(argv[2]); // Porqué dereferenciamos argv en la posición 2?

  // Cálculo de la integral
  // Vamos a usar el punto medio de los rectángulos para evaluar la función
  double sum = 0.0; // Valor de la suma
  double w = 1.0 / n; // Número de particiones
  
  // Toma el tiempo antes de empezar la operacion
  double time_1 = seconds();

  #pragma omp parallel
  {
  #pragma omp for reduction(+:sum)
  for(int i = 0; i < n; ++i){
    double x = w * (i - 0.5); // Variable independiente
    double tempSum = 4.0 / (1.0 + (x * x)); // Evaluamos la función en el valor de x
    sum += tempSum;
  }
  // sum es una variable que contiene la altura de los rectangulos
  // area = altura * base
  }
  double pi_approx = sum * w;

  // Toma el tiempo tras la operacion
  double time_2 = seconds();

  std::cout.precision(10);
  std::cout << pi_approx << " " << time_2 - time_1 << std::endl;
  
  return 0;
}
