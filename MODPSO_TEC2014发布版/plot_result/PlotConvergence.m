% %字号一定要和论文字号大小一样，一般都是12号的
% 
% x = 1:1:50;
% subplot(1,2,1);
% Q = [0.325773 0.381328 0.396861 0.399326 0.399326 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105];
% y1=plot(x',Q,'b-');
% hold on;
% LPAQ = [0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598];
% y2=plot(x',LPAQ,'r-');
% MemenetQ=[0.2334 0.3905  0.3905 0.3905 0.3905 0.3905 0.3905 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.402 0.4020];
% y3=plot(x',MemenetQ,'k-');
% % text('karate club');
% xlabel('generations');
% ylabel('Modularity');
% legend('pso with random initialization','pso with label propagation','Meme-net with heuristic');
% set(gca,'linewidth',2.0);
% set(y1,'linewidth',2.0);
% set(y2,'linewidth',2.0);
% set(y3,'linewidth',2.0);
% hh=findobj('tag','legend') ;
% set(hh,'fontsize',12) ;
% set(gca,'fontsize',12);
% set(get(gca,'xlabel'),'fontsize',12);
% set(get(gca,'ylabel'),'fontsize',12);
% hold off;
% subplot(1,2,2);
% x1 = 1:1:50;
% Q1 = [0.395488 0.473027 0.489805 0.507441 0.523652 0.524238 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902];
% y1=plot(x1',Q1,'b-');
% hold on;
% LPAQ1 = [0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902];
% y2=plot(x1',LPAQ1,'r-');
% MemenetQ1=[0.4868    0.4868    0.4868    0.4869    0.4878    0.4878    0.4878    0.4878    0.5009    0.5009    0.5009    0.5009    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096];
% y3=plot(x1',MemenetQ1,'k-');
% % text('dolphins');
% xlabel('generations');
% ylabel('Modularity');
% legend('pso with random initialization','pso with label propagation','Meme-net with heuristic');
% set(gca,'linewidth',2.0);
% set(y1,'linewidth',2.0);
% set(y2,'linewidth',2.0);
% set(y3,'linewidth',2.0);
% hh=findobj('tag','legend') ;
% set(hh,'fontsize',12) ;
% set(gca,'fontsize',12);
% set(get(gca,'xlabel'),'fontsize',12);
% set(get(gca,'ylabel'),'fontsize',12);


%字号一定要和论文字号大小一样，一般都是12号的
%分开画版本
figure(1);
x = 1:1:50;
Q = [0.325773 0.381328 0.396861 0.399326 0.399326 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105 0.415105];
y1=plot(x',Q,'-b*');
hold on;
LPAQ = [0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598 0.415598];
y2=plot(x',LPAQ,'-rd');
MemenetQ=[0.2334 0.3905  0.3905 0.3905 0.3905 0.3905 0.3905 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.4020 0.402 0.4020];
y3=plot(x',MemenetQ,'-kh');
% text('karate club');
xlabel('generations');
ylabel('Modularity');
legend('DPSO with random initialization','DPSO with label propagation','Meme-net with heuristic');
set(gca,'linewidth',2.0);
set(y1,'linewidth',2.0);
set(y2,'linewidth',2.0);
set(y3,'linewidth',2.0);
hh=findobj('tag','legend') ;
set(hh,'fontsize',12) ;
set(gca,'fontsize',12);
set(get(gca,'xlabel'),'fontsize',12);
set(get(gca,'ylabel'),'fontsize',12);
hold off;
figure(2);
x1 = 1:1:50;
Q1 = [0.395488 0.473027 0.489805 0.507441 0.523652 0.524238 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902];
y1=plot(x1',Q1,'b-');
hold on;
LPAQ1 = [0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902 0.524902];
y2=plot(x1',LPAQ1,'r-');
MemenetQ1=[0.4868    0.4868    0.4868    0.4869    0.4878    0.4878    0.4878    0.4878    0.5009    0.5009    0.5009    0.5009    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096    0.5096];
y3=plot(x1',MemenetQ1,'k-');
GA_dolphins_Q=[0.4280    0.4273    0.4273    0.4273    0.3927    0.3927    0.3927    0.3927    0.3927    0.3927    0.3927    0.4852    0.4852    0.4852    0.4612    0.4612    0.4612    0.4612    0.4612    0.4612    0.4612    0.4612    0.4612    0.4597    0.4597    0.4597    0.4597    0.4717    0.4717    0.4717    0.4717    0.4660    0.4660    0.4660    0.4660    0.4660    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955    0.4955];
y4=plot(x1',GA_dolphins_Q);
% text('dolphins');
xlabel('generations');
ylabel('Modularity');
legend('DPSOCD with random initialization','DPSOCD with label propagation','Meme-net with heuristic','GA-net with neighbor based method');
set(gca,'linewidth',2.0);
set(y1,'linewidth',2.0);
set(y2,'linewidth',2.0);
set(y3,'linewidth',2.0);
set(y4,'linewidth',2.0);
hh=findobj('tag','legend') ;
set(hh,'fontsize',12) ;
set(gca,'fontsize',12);
set(get(gca,'xlabel'),'fontsize',12);
set(get(gca,'ylabel'),'fontsize',12);