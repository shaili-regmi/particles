# particles

Implements particle systems using openGL

TODO: Add a representative image for your project here

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake -G "Visual Studio 16 2019" ..
particles/build $ start CS312-Particles.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
particles/build $ ../bin/Debug/billboard
particles/build $ ../bin/Debug/confetti
particles/build $ ../bin/Debug/demo
```

*macOS*

Open terminal to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake ..
particles/build $ make
```

To run each program from build, you would type

```
particles/build $ ../bin/billboard
particles/build $ ../bin/confetti
particles/build $ ../bin/demo
```

# Results

TODO: Show your work

## Billboard 

*images - 1) untransformed, 2) scaled and translated, 3) +view-projection applied, 4) +rotation applied*

[!billboard](https://github.com/shaili-regmi/particles/blob/main/billboard.png)


## Confetti

*images - 1) 1 particle, 2) pre-sorting, 3) post-sorting*

[!confetti](https://github.com/shaili-regmi/particles/blob/main/confetti.png)


# Unique Demo - Smoke Plumes

## Smoke Flare

*Particles get bigger and more transparent with each update*

*Particles that go offscreen are reused by respawing at initial position with original transparency*

[!smoke](https://github.com/shaili-regmi/particles/blob/main/smoke%20flare.png)
