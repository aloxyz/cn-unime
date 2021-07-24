%Verifica il teorema di topologica equivalenza sulle 3 matrici per le 4
%norme matriciali studiate.

n = input("Inserisci ordine: ");
%Saranno usate: 
%Matrice di Vandermonde
%Matrice di Hilbert
%Matrice tridiagonale




r1 = rand(n, 1);
V = vander(r1);
H = hilb(n);

r2 = rand((n-1), 1);
D = diag(r1) + diag(r2, +1) + diag(r2, -1);


M = {V, H, D};
for i = 1:3
    display("M{"+i+"}")
    
    verify(1/sqrt(n)*norm(M{i},'inf'), norm(M{i}, 2), sqrt(n)*norm(M{i},'inf'))
    verify(1/sqrt(n)*norm(M{i},1), norm(M{i}, 2), sqrt(n)*norm(M{i},1))
    verify(max(max(abs(M{i}))), norm(M{i}, 2), n*max(max(abs(M{i}))))
    
    display(norm(M{i},2)+ " <= "+ sqrt(norm(M{i}, 1) * norm(M{i}, 'inf')))
    if norm(M{i},2) <= sqrt(norm(M{i}, 1) * norm(M{i}, 'inf'))
        display("Verificato")
    else
        display("Non verificato")
    end
end

function verify(a,b,c)

display(a+" <= " + b + " <= "+ c)
    if a <= b && b <= c
        display("Verificato")
    else
        display("Non verificato")
    end

end



