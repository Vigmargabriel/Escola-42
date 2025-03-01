#!/bin/bash
# Este script imprime a lista de todos os arquivos ignorados pelo Git no repositório atual

git ls-files --others --ignored --exclude-standard
