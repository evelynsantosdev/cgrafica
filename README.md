# Sistema de Tiles – OpenGL em C++

Este projeto é uma evolução de um motor simples em OpenGL, inspirado em jogos estilo DOOM, com foco na renderização de cenários baseados em tiles carregados a partir de arquivos `.txt`.

O objetivo principal foi expandir o sistema de tiles para suportar múltiplos tipos de chão, paredes diferentes e teto opcional, mantendo a integração com o fluxo original do projeto.

---

## Objetivos do Trabalho
**Evoluir o sistema de tiles para suportar:**
-  Pelo menos **2 tipos de parede**, cada uma com sua própria textura
-  Pelo menos **2 tipos de chão**, cada um com sua própria textura
-  **Teto opcional**, permitindo áreas cobertas e áreas abertas
-  Carregamento do mapa a partir de arquivo `.txt`
-  Integração com `MapLoader` e `drawLevel`
-  Código compilando e executando normalmente

---

## Funcionalidades Implementadas

### Pisos
- Dois tipos de chão diferentes (`0` e `3`)
- Cada tipo utiliza uma textura distinta

### Paredes
- Dois (ou mais) tipos de paredes (`1`, `2`, `Y`)
- Cada parede pode usar uma textura própria

### Teto Opcional
- Tiles marcados com `T` possuem teto
- Áreas sem `T` permanecem abertas
- O teto é renderizado com uma textura específica

---

## Estrutura do Sistema

- **MapLoader**  
  Responsável por carregar o mapa a partir de um arquivo `.txt`.

- **drawLevel**  
  Interpreta os caracteres do mapa e desenha:
  - chão
  - paredes
  - teto (quando aplicável)
  - tiles especiais

Toda a lógica foi integrada ao fluxo original do projeto, sem quebrar funcionalidades existentes.

---

## Execução

O projeto utiliza:

- OpenGL
- FreeGLUT
- GLEW
- MSYS2 (MinGW64)
- C++17

Após a compilação, o cenário é renderizado automaticamente com base no mapa carregado.

---

## Conclusão

O sistema de tiles foi expandido com sucesso, permitindo maior variedade visual e estrutural no cenário, atendendo completamente aos requisitos da atividade proposta.

O uso de diferentes texturas e a possibilidade de teto opcional tornam o mapa mais rico e flexível para futuras expansões.

---

## Autor

Projeto desenvolvido como atividade acadêmica para a disciplina de Computação Gráfica.


