#include <iostream>
#include <complex>
#include <omp.h>
#include <vector>
#include <sys/time.h>

// Función para determinar si un número c está fuera o dentro del conjunto
// de Maldenbrot con la cantidad de iteraciones máximas
int mandelbrot(const std::complex<double> &c, const int &maxits){
  std::complex<double> z = 0;
  int n = 0;
  while(abs(z) <= 2 && n < maxits){
    z = z * z + c;
    ++n;
  }
    
  return n;
}

double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;

  return sec;
}

int main(){

  // Ancho y alto de la salida del programa
  int width = 150;
  int height = 45;
  // Número máximo de iteraciones (corte)
  int max_iter = 1000;
  // Coordenadas en el plano complejo máximas y mínimas
  double minX = -2.0, maxX = 1.0;
  double minY = -1.0, maxY = 1.0;

  // Rutina principal para generar e imprimir el conjunto

  std::vector<char> Cols(height * width);

  double time_1 = seconds(); 
  
  
  #pragma omp parallel
  {
    #pragma omp for
    for (int y = 0; y < height; ++y) {
      #pragma omp task
      {
      for (int x = 0; x < width; ++x) {
        // Mapeo de pixeles a número complejo
        std::complex<double> c(minX + (maxX - minX) * x / width,
        minY + (maxY - minY) * y / height);
        // Calculo del número de iteraciones
        int n = mandelbrot(c, max_iter);

	// Se imprime un caracter dependiendo del número de iteraciones
	if (n == max_iter) {
	  Cols[y * width + x] = '#'; // Dentro del conjunto de Mandelbrot
        } 
	else {
          Cols[y * width + x] = '.'; // Fuera del conjunto de Mandelbrot
        }
      }
      }
    }
 }
  double time_2 = seconds();

  for(int y = 0; y < height; ++y){
	for(int x = 0; x<width; ++x){
  		std::cout << Cols[(y * width) + x];
  	}
	std::cout << std::endl;
  }

  std::cout << "Velocity: " << 0.0736918/(time_2 - time_1) << std::endl;
  return 0;
  }
