# Entropia de Tsallis para segmentação de imagens

Esse projeto é uma pesquisa com o intuito de utilizar a entropia de Tsallis para segmentar imagens monocromáticas por meio da limiarização. 

Para essa pesquisa foi utilizado a proposta de segmentação recursiva, em que após cada segmentação, cada faixa de intervalo seria considerado uma nova imagem, podendo assim ser segmentada novamente quantas vezes for necessário. Para isso foi utilizado uma heurística baseada no enxame de partículas para definir o melhor parâmetro Q. Após isso percorre o intervalo de tons da imagem para definir o melhor T para a limiarização.

_Segue abaixo alguns dos resultados obtidos:_


| Imagem 1 | Imagem 2 |
| ------------- | ------------- |
| ![](images/55067/55067.jpg.jpg?raw=true) | ![](images/238011/238011.jpg.jpg?raw=true)
| _Imagem 1 original_ | _Imagem 2 original_ |
| ![](images/55067/1.116.jpg?raw=true) | ![](images/238011/1.87.jpg?raw=true) |
| _Imagem 1 segmentada com limiar T = 116_ | _Imagem 2 segmentada com limiar T = 87_ |
| ![](images/55067/2.59-178.jpg?raw=true) | ![](images/55067/2.60-144.jpg?raw=true) |
| _Imagem 1 segmentada com limiar T1 = 59 e T2 = 178_ | _Imagem 2 segmentada com limiar T1 = 60 e T2 = 144_ | 
