#version 120
uniform float uTime;
uniform vec3 uBaseColor;
varying vec2 vTexCoord;
void main() {
    // Rotação contínua em uma direção (sentido horário)
    float rotation = uTime * 1.0;
    
    // Calcula ângulo da posição atual
    vec2 center = vec2(0.5, 0.5);
    vec2 pos = vTexCoord - center;
    float angle = atan(pos.y, pos.x);
    
    // Adiciona rotação ao ângulo
    float rotatedAngle = angle + rotation;
    
    // Cria padrão de divisão em setores (metade verde, metade amarelo)
    float sector = mod(rotatedAngle + 3.14159, 6.28318) / 6.28318;
    
    vec3 color1 = vec3(0.2, 1.0, 0.2);  // verde brilhante
    vec3 color2 = vec3(1.0, 1.0, 0.0);  // amarelo brilhante
    
    // Transição suave entre as cores
    vec3 finalColor = mix(color1, color2, smoothstep(0.4, 0.6, sector));
    
    // Brilho uniforme
    finalColor *= 1.2;
    
    gl_FragColor = vec4(finalColor, 1.0);
}
