# TinyEurocat

A simple EuroScope plug-in to simulate THALES Eurocat TAG items

<hr>

## Installation

### 1. Load the plug-in

In order to install the plug-in, extract the DLL file to whererver you want, then load the plug-in from OTHER SETS -> Plug-ins -> Load

### 2. Config the TAGs

Open OTHER SETS -> TAG Editor, and manually replace default altitude, cleared altitude and speed item with the one starts with TinyEurocat.

## Features
 - Current altitude, Cleared altitude and current speed in metric
 - show nohing when cleared altitude is 0

## Changlog

### v1.0.1

 - Current altitude, Cleared altitude and current speed in metric
 - show nohing when cleared altitude is not assigned instead of 0 or crz altitude

### v1.0.2

 - fix current altitude accuracy
 - fix cleared alt to adapt china rvsm
 - check if cleared alt is valid to rvsm
 - remove cleared alt when equals final alt

## v1.1.1

 - change license and copyright holder
 - remove force rvsm
 - change ``GS`` source
 - change ``CFL`` algorithm

## v1.2.1

 - add both ``Reported GS`` and ``Calculated GS``