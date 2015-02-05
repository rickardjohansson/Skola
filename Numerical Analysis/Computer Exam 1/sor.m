function [ x ] = sor( A, b, x0, w, tol )
% beräknar lösningen x ur matrisekvationen A*x = b med hjälp av succesive
% over relaxation. x0 är en första gissning på lösningen, en startvektor. 
% w är en parameter som kan användas för optimering av metoden, 1<=w<=2.
% tol är hur exakt metoden ska beräkna svaret med avseende på residualen.

U = triu(A, 1);
L = tril(A, -1);
D = diag(diag(A));

res = 100;

while tol < res
    
    % lösningen beräknas genom definitionen av SOR.
    x1 = (w*L + D)\((1-w)*D*x0 - w*U*x0) + ((D + w*L))\b*w;
    
    % residualen beräknas för att se om den är mindre än den angivna
    % toleransen
    res = norm(A*x1-b, inf)/norm(b, inf);
    
    x0 = x1;

end

x = x1;

end

