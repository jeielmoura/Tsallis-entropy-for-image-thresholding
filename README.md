# Entropia de Tsallis para segmentação de imagens

Esse projeto é uma pesquisa com o intuito de utilizar a entropia de Tsallis para segmentar imagens monocromáticas por meio da limiarização. 

Para essa pesquisa foi utilizado a proposta de segmentação recursiva, em que após cada segmentação, cada faixa de intervalo seria considerado uma nova imagem, podendo assim ser segmentada novamente quantas vezes for necessário. Para isso foi utilizado uma heurística baseada no enxame de partículas para definir o melhor parâmetro Q. Após isso percorre o intervalo de tons da imagem para definir o melhor T para a limiarização.

_Segue abaixo alguns dos resultados obtidos:_ 


| Imagem | Uma segmentação | Duas segmentações |
| ------------- | ------------- | ------------- |
| ![](images/55067/55067.jpg.jpg?raw=true) | ![](images/55067/1.116.jpg?raw=true) | ![](images/55067/2.59-178.jpg?raw=true) |
|  | _T = 116, Q = 2.065_ |  _T1 = 59, Q1 = 0.020 e T2 = 178, Q2 = 0.672_ |
| ![](images/238011/238011.jpg.jpg?raw=true) | ![](images/238011/1.87.jpg?raw=true) | ![](images/238011/2.60-144.jpg?raw=true) |
|  | _T = 87, Q = 1.854_ | _T1 = 60, Q1 = 0.269 e T2 = 144, Q2 = 0.038_ |
| ![](images/241004/241004.jpg.jpg?raw=true) | ![](images/241004/1.138.jpg?raw=true) | ![](images/241004/2.81-196.jpg?raw=true) |
|  | _T = 138, Q = 0.043_ | _T1 = 81, Q1 = 0.0489 e T2 = 196, Q2 = 0.0126_ |

| Imagem | Uma segmentação | Duas segmentações |
| ------------- | ------------- | ------------- |
| ![](images/55067/55067.jpg.jpg?raw=true) | ![](images/55067/1.116.jpg?raw=true) | ![](images/55067/2.59-178.jpg?raw=true) |
|  | _Qmin = 0.074, Qmax = 3.407_ |  _Q1min = 0.020, Q1max = 0.945, _Q2min = 0.016, Q2max = 1.822_ |
| ![](images/238011/238011.jpg.jpg?raw=true) | ![](images/238011/1.87.jpg?raw=true) | ![](images/238011/2.60-144.jpg?raw=true) |
|  | _Qmin = 0.475, Qmax = 3.332_ | _Q1min = 0.000, Q1max = 1.428, _Q2min = 0.044, Q2max =1.289_ |
| ![](images/241004/241004.jpg.jpg?raw=true) | ![](images/241004/1.138.jpg?raw=true) | ![](images/241004/2.81-196.jpg?raw=true) |
|  | _Qmin = 0.005, Qmax =1.637_ | _Q1min = 0.000, Q1max = 1.107, _Q2min = 0.006, Q2max = 0.933_ |