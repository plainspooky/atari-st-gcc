#!/usr/bin/env bash

EMUTOS_FILE='etos512k.img'
EMUTOS_ZIP='emutos-512k-latest.zip'
EMUTOS_URL='https://sourceforge.net/projects/emutos/files/latest/download'

for program in 'unzip' 'wget'; do
    [[ ! $( which $program ) ]] && apt-get install --yes $program
done

wget --output-document="$EMUTOS_ZIP" "$EMUTOS_URL"

unzip -j "$EMUTOS_ZIP" *.img
cp "$EMUTOS_FILE" /vagrant
