%(Il problema del filtraggio o denoising) 
%Dato il segnale f(x) affetto da rumore ricostruire al meglio il
%segnale pulito s(x).


range = [0, 2*pi];
points = 256;
x = linspace(range(1), range(2), points); %ascisse punti di approssimazione
s = ((x-1.2).*sin(3*x)+sin(1+x.*x)./(x+1)).*sin(x/2); %Funzione originale
r = 0.1*sin(7*x)+2*sin(23*x).*cos(31*x).*sin(1-19*x); %Funzione rumore
f = s + r; %ordinate punti di approssimazione

xg = union(linspace(range(1), range(2), 1000),x); %ascisse punti di graficazione
yg = {((xg-1.2).*sin(3*xg)+sin(1+xg.*xg)./(xg+1)).*sin(xg/2)}; %ordinate punti di graficazione
fg = yg{1} + (0.1*sin(7*xg)+2*sin(23*xg).*cos(31*xg).*sin(1-19*xg));
errori = ones(1,points-2);

minimum = Inf;
for i = 2:points-1
   V = flip(vander(x),2);
   V = V(:,1:i);
   a = flip(linsolve(V,f')); %Polinomio approssimante di grado i
   pn = polyval(a,x);
   
   errori(i-1) = norm(pn-f); %Calcola la norma del vettore errore
   
   pn = pn - f; 
   
   norma = 0;
   for j = 1:max(size(pn)) %Calcola il quadrato della norma euclidea
    norma = norma + (pn(j)*pn(j));
   end
   
   if minimum > norma      %Trova il minimo quadrato della norma
       minimum = norma;
       pol = a;
       
   end
end

yg{2} = polyval(pol,xg);
figure(1)
plot(xg, fg, "g");
hold on
plot(xg,yg{1}, "r");
plot(xg, yg{2}, "b");
plot(xg, abs(yg{2}-yg{1}), "y");
plot(x, f, "ko");
legend("s(x) + r(x)", "s(x)", "p(x)", "Errore assoluto tra p(x) e s(x)", "punti di approssimazione");
xlim([range(1),range(2)]);
ylim([min(min(yg{1}), min(yg{2})), max(max(yg{1}), max(yg{2}))]);
title("Polinomio approssimante di grado", max(size(pol))-1);

uitable(figure(2), 'Data', errori', 'ColumnName','Errore', 'RowName', 1:points-1);
