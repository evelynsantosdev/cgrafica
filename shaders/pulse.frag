#version 120
uniform float uTime;
uniform vec3 uBaseColor;
varying vec2 vTexCoord;

void main() {
    vec2 center = vec2(0.5, 0.5);
    vec2 pos = vTexCoord - center;
    float dist = length(pos);
    float angle = atan(pos.y, pos.x);
    
    // Cores base vibrantes (verde e amarelo alternando)
    vec3 color1 = vec3(0.2, 1.0, 0.3);
    vec3 color2 = vec3(1.0, 0.9, 0.0);
    
    float colorCycle = sin(uTime * 2.0) * 0.5 + 0.5;
    vec3 baseColor = mix(color1, color2, colorCycle);
    
    // Iluminação básica girando
    float lightRotation = uTime * 1.5;
    vec2 lightDir = vec2(cos(lightRotation), sin(lightRotation));
    vec2 normal = normalize(pos);
    float diffuse = max(dot(normal, lightDir), 0.0);
    float shading = 0.4 + diffuse * 0.6;
    
    // LINHA DIAGONAL BRILHANTE (efeito shine)
    float speed = 1.0;
    float line_width = 0.15;
    float offset = 2.0;
    float pause_duration = 0.5;
    
    // Ciclo com pausa
    float cycle_duration = offset + pause_duration;
    float adjusted_time = mod(uTime * speed, cycle_duration);
    
    // Posição da linha (direita para esquerda)
    float line_position;
    if (adjusted_time <= offset) {
        line_position = offset - adjusted_time;
    } else {
        line_position = -0.5; // fora da tela durante pausa
    }
    
    // Rotação diagonal (45 graus)
    vec2 rotated_uv = vec2(vTexCoord.x + vTexCoord.y, vTexCoord.y - vTexCoord.x) * 0.5;
    float line_dist = abs(rotated_uv.x - line_position);
    
    // Intensidade da linha brilhante
    float line_intensity = smoothstep(line_width, 0.0, line_dist);
    
    // Cor da linha (branco brilhante)
    vec3 line_color = vec3(1.5, 1.5, 1.5);
    
    // Reflexo especular
    vec2 viewDir = vec2(0.0, 1.0);
    vec2 halfVec = normalize(lightDir + viewDir);
    float specular = pow(max(dot(normal, halfVec), 0.0), 32.0);
    
    // Fresnel
    float fresnel = pow(1.0 - min(dist * 1.3, 1.0), 3.0);
    
    // Combina tudo
    vec3 finalColor = baseColor * shading;
    finalColor += vec3(1.0, 1.0, 1.0) * specular * 0.5;
    finalColor += baseColor * fresnel * 0.3;
    finalColor = mix(finalColor, line_color, line_intensity * 0.9); // linha brilhante
    
    // Profundidade
    float depth = 1.0 - smoothstep(0.0, 0.7, dist);
    finalColor *= (0.8 + depth * 0.4);
    
    gl_FragColor = vec4(finalColor, 1.0);
}