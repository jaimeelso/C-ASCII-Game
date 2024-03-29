# C ASCII Game

![Language](https://img.shields.io/badge/Language-C-red?style=for-the-badge) ![Version](https://img.shields.io/badge/Version-4.1-blue?style=for-the-badge) ![License](https://img.shields.io/github/license/jaimeelso/C-ASCII-Game?style=for-the-badge)

<p align="center">
    <img src="https://raw.githubusercontent.com/jaimeelso/C-ASCII-Game/master/logo.png">
</p>

"Minas de Rococo" is a **graphical adventure** made in **C** with **ASCII graphics** executed in the terminal. In this adventure you will live the experience of rescue your best friend from a drunkenness in a disgusting nightclub. To achieve this you will have to advance through the different levels talking with different people and getting certain objects. 

## Install

Download the tablet from this repository or clone it by terminal using the command:

```shell
git clone https://github.com/jaimeelso/C-ASCII-Game.git
```

With the terminal, go to the root folder and execute this two comands:

```shell
make
make run
```

You have to have the **gcc compiler** installed on your computer to compile the code.

## How it works

_

### Commands

```shell
quit / q                                Salir
avanzar / a                             Ir
    norte / n                               al norte
    sur / s                                 al sur
    oeste / o                               al oeste
    este / e                                al este
    arriba / ar                             arriba
    abajo / aba                             abajo
coger / c + (nombre del objeto)         Coger objeto
dejar / d + (nombre del objeto)         Dejar objeto
inspeccionar / i +                      Inspeccionar
    espacio / e                             espacio
    (nombre objeto)                         objeto
turnon + nombre objeto                  Encender objeto
turnoff + nombre objeto                 Apagar objeto
guardar / g + nombre partida            Guardar
hablar / h + nombre personaje           Hablar
beber / b + copa                        Beber Copa
```

## How to run the tests

_

## License

C ASCII GAME is licensed under the [MIT License](https://github.com/jaimeelso/C-ASCII-Game/blob/master/LICENSE)

## Authors

- [Jaime Elso de Blas](https://jaimeelso.com/) - **Developer**
- Sergio García Bordonado - **Game Designer**
- Alfredo de Frutos Estebaranz - **Developer**
- Sung Pil Choi - **Tester**
