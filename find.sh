#!/bin/bash

# Esse script é responsável por buscar um texto em todos os arquivos de uma pasta,
# incluido subpastas.
#
# Particularmente utilizado para verificar se um aluno está explicitamente imprimindo
# a resposta esperada para o caso de teste sem implementar a lógica necessária para tal.
#
# Uso:
#   ./find_text.sh <pasta> <arquivo_texto>
#
# Cada linha do arquivo de texto é um texto a ser buscado nos arquivos da pasta.

function find_text() {
    local pasta="$1"
    local arquivo_texto="$2"

    while IFS= read -r texto; do # Read each line of the file
        if [ -n "$texto" ]; then
            echo "Buscando texto: $texto"
            find_text_helper "$pasta" "$texto"
        fi
    done < "$arquivo_texto"
}

function find_text_helper() {
    local pasta="$1"
    local texto="$2"

    for arquivo in "$pasta"/*; do
        if [ -d "$arquivo" ]; then # If it's a directory, then call the function recursively
            find_text_helper "$arquivo" "$texto"

        elif [ -f "$arquivo" ]; then # If it's a file, then search for the text
            if [ -r "$arquivo" ]; then
                if grep -q "$texto" "$arquivo"; then
                    echo "Texto encontrado em: $arquivo"
                    grep -n "$texto" "$arquivo"
                    echo
                fi
            fi
        fi
    done
}

if [ "$#" -ne 2 ]; then
    echo "Uso: $0 <pasta> <arquivo_texto>"
    exit 1
fi

pasta="$1"
arquivo_texto="$2"

if [ ! -d "$pasta" ]; then
    echo "Pasta não encontrada: $pasta"
    exit 1
fi

if [ ! -f "$arquivo_texto" ]; then
    echo "Arquivo de texto não encontrado: $arquivo_texto"
    exit 1
fi

find_text "$pasta" "$arquivo_texto"
