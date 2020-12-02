# Snake -> Dev-ART - ft.freddy.   <!-- omit in toc -->
[Pagina con Instrucciones(https://wmoralesdev.github.io/actividadfinal/index)](https://wmoralesdev.github.io/actividadfinal/index)

## Ver Readme :  <!-- omit in toc -->
[<img src="https://www.ciesi.net/images/boton-clic-aqui.png" width="150" height="50">](https://drubico.github.io/Snake_Terminal_cpp)

## Ver documento donde nos basamos :
[<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8a/Icon-doc.svg/810px-Icon-doc.svg.png" width="50" height="50">](https://docs.google.com/document/d/1vROBoDUtuphx_JmOmtY_wQ03JmSLFBe3MnIY0XbRCk8/edit)

## Indice <!-- omit in toc -->
- [Estudiantes](#estudiantes)
- [Capturas de pantalla:](#capturas-de-pantalla)
  - [inicio(usuario):](#iniciousuario)
    - [Primera Vez](#primera-vez)
    - [Usuario ya guardado:](#usuario-ya-guardado)
  - [MENU](#menu)
    - [Start(Modos de juego)](#startmodos-de-juego)
      - [SNAKE WORLD  PARTY (Cambia el tamaño de la pantalla segun el nivel)](#snake-world--party-cambia-el-tamaño-de-la-pantalla-segun-el-nivel)
        - [Nivel Facil (Mitad de pantalla)](#nivel-facil-mitad-de-pantalla)
        - [Nivel Normal (Pantalla en 60%)](#nivel-normal-pantalla-en-60)
        - [Nivel Dificil (pantalla completa)](#nivel-dificil-pantalla-completa)
      - [CLASICO 97](#clasico-97)
      - [ESPECIAL](#especial)
        - [LIBRE](#libre)
        - [CERRADO](#cerrado)
        - [EXTRA](#extra)
    - [Tienda](#tienda)
    - [Ver Tops](#ver-tops)
      - [Tipos de top](#tipos-de-top)
        - [Top World Party](#top-world-party)
        - [Top Clasico 97](#top-clasico-97)
    - [Instrucciones](#instrucciones)
    - [Exit](#exit)
- [Implementacion de :](#implementacion-de-)
  - [Buenas prácticas:](#buenas-prácticas)
  - [Estructuras de datos (dinámicas):](#estructuras-de-datos-dinámicas)
  - [Algoritmos de ordenamiento / búsqueda:](#algoritmos-de-ordenamiento--búsqueda)
- [EJECUCION:](#ejecucion)
  - [Ejecutar codigo:](#ejecutar-codigo)

# Estudiantes

- Diego Alejandro Rubi Cordova 00121117
- Luis Adalberto Trujillo Perez 00127717
- Cristian Mauricio Alfaro Contreras 00167917
- Fredy Alexander Sánchez Pérez 00082817

# Capturas de pantalla:
##  inicio(usuario):
### Primera Vez
<img width="1000" height="250" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0001.png" />
<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0002.png" />

### Usuario ya guardado:
<img width="1000" height="250" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0003.png" />

##  MENU
<img width="1000" height="300" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0004.png" />

### Start(Modos de juego)
<img width="1000" height="300" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0005.png" />

#### SNAKE WORLD  PARTY (Cambia el tamaño de la pantalla segun el nivel)

##### Nivel Facil (Mitad de pantalla)
<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0006.png" />

##### Nivel Normal (Pantalla en 60%)
<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0007.png" />

##### Nivel Dificil (pantalla completa)
<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0008.png" />

#### CLASICO 97
<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0009.png" />

#### ESPECIAL

<img width="1000" height="250" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0010.png" />

Cada Especial tiene un nivel
<img width="1000" height="250" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0011.png" />

##### LIBRE

No tiene paredes
<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0012.png" />

##### CERRADO
Tiene paredes
<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0013.png" />

##### EXTRA
Mapas cargados desde un csv

<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0014.png" />

### Tienda
<img width="1000" height="250" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0015.png" />

### Ver Tops

<img width="1000" height="250" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0016.png" />

#### Tipos de top

<img width="1000" height="250" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0017.png" />

##### Top World Party
<img width="1000" height="300" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0018.png" />

##### Top Clasico 97
<img width="1000" height="300" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0019.png" />

### Instrucciones

<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0020.png" />

### Exit
Cuando salimos guarda nuestros resultados
<img width="1000" height="400" src="https://raw.githubusercontent.com/00121117-Archivos/AA_Snake/main/0021.png" />


# Implementacion de :
## Buenas prácticas:

## Estructuras de datos (dinámicas):

## Algoritmos de ordenamiento / búsqueda:


# EJECUCION:
## Ejecutar codigo:
Para correr se necesita una terminal kernel GNU/linux:
en la raiz de el proyecto ejecutar:
```
g++ -pthread main.cpp -o main && ./main
```

