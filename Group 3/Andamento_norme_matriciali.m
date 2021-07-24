%Calcola l'andamento delle norme matriciali studiate per l'ordine che va da
%2 a n
n = input("Ordine massimo: ");

%Saranno usate: 
%Matrice di Vandermonde
%Matrice di Hilbert
%Matrice tridiagonale

norms = {ones(1,n-1), ones(1,n-1), ones(1,n-1), ones(1,n-1)};
norms = {norms, norms};
matrici = {};
triplet = [-1, 0, 1];

for i = 2:n
    matrici{1} = matWilk(i, triplet);
    matrici{2} = hilb(i);
    
    for j = 1:2
       norms{j}{1}(i-1) = norm(matrici{j}, 1); 
       norms{j}{2}(i-1) = norm(matrici{j}, 2); 
       norms{j}{3}(i-1) = norm(matrici{j}, 'fro'); 
       norms{j}{4}(i-1) = norm(matrici{j}, 'inf'); 
    end
    
end

colors = ['r', 'b', 'g', 'y'];

for i = 1:2
    figure(i)
    for j = 1:4
        plot(2:n, norms{i}{j}, colors(j));
        hold on
    end
    if i == 1
        title("Wilkinson");
    else
        title("Hilbert");
    end
legend("Norma 1", "Norma 2", "Norma Frobenius", "Norma Inf");    
end


function A = matWilk(n, triplet)

    A = ones(n+1,n) * triplet(2);
    for i = 1:2:n-1
        A(i,n) = triplet(1);
        A(i+1,n) = triplet(3);
    end
    for i = 1:n
        A(i,i) = triplet(3);
        A(i+1,i) = triplet(3);
    end

    for j = 1:n-2
        for i = j+2:2:n
            A(i,j) = triplet(1);
            A(i+1,j) = triplet(3);
        end
    end
    
    A = A(1:n,:);
end