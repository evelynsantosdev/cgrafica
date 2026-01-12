## Correção de Iluminação Indoor / Outdoor (Trabalho Acadêmico)

Projeto desenvolvido no contexto da disciplina de Computação Gráfica, utilizando OpenGL para simular ambientes internos (indoor) e externos (outdoor) com diferentes modelos de iluminação.

Foi identificado um problema em que paredes localizadas na fronteira entre ambientes indoor e outdoor eram iluminadas apenas como indoor. Isso ocorria porque a iluminação indoor era aplicada como estado global antes do desenho das paredes, fazendo com que todas as suas faces herdassem essa iluminação, inclusive as voltadas para o exterior.

### Solução Implementada

A solução proposta e implementada consistiu em remover a aplicação da iluminação indoor nas paredes, mantendo-a apenas no chão e no teto dos ambientes internos. Dessa forma, as paredes passam a ser iluminadas exclusivamente pela luz global (sol), corrigindo o problema visual na transição entre ambientes internos e externos.

### Resultado

- Iluminação correta na fronteira indoor/outdoor  
- Transição visual consistente entre ambientes  
- Alteração mínima no código base
