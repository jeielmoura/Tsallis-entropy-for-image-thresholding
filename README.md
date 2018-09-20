# Entropia de Tsallis para segmentação de imagens

Esse projeto é uma pesquisa com o intuito de utilizar a entropia de Tsallis para segmentar imagens monocromáticas por meio da limiarização. 

Para essa pesquisa foi utilizado a proposta de segmentação recursiva, em que após cada segmentação, cada faixa de intervalo seria considerado uma nova imagem, podendo assim ser segmentada novamente quantas vezes for necessário. Para isso foi utilizado uma heurística baseada no enxame de partículas para definir o melhor parâmetro Q. Após isso percorre o intervalo de tons da imagem para definir o melhor T para a limiarização.

_Segue abaixo alguns dos resultados obtidos:_ 


| Imagem | Uma segmentação | Duas segmentações |
| ------------- | ------------- | ------------- |
| ![](images/55067/55067.jpg.jpg?raw=true) | ![](images/55067/1.116.jpg?raw=true) | ![](images/55067/2.59-178.jpg?raw=true) |
| _Imagem 1 original_ | _Imagem 1 segmentada com limiar T = 116_ | _Imagem 1 segmentada com limiar T1 = 59 e T2 = 178_ |
| ![](images/238011/238011.jpg.jpg?raw=true) | ![](images/238011/1.87.jpg?raw=true) | ![](images/238011/1.60-144.jpg?raw=true) |
| _Imagem 2 original_ | _Imagem 2 segmentada com limiar T = 87_ | _Imagem 2 segmentada com limiar T1 = 60 e T2 = 144_ |
| ![](images/241004/241004.jpg.jpg?raw=true) | ![](images/241004/1.138.jpg?raw=true) | ![](images/241004/2.81-196.jpg?raw=true) |
| _Imagem 3 original_ | _Imagem 3 segmentada com limiar T = 138_ | _Imagem 3 segmentada com limiar T1 = 81 e T2 = 196_ |