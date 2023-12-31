import numpy as np
from os.path import exists
import readOutputFile
import os

# Raises value error if wrong things are input.
def value_error_f(t,val):
    try:
        t(val)
        return True
    except ValueError:
        return False

### Asking the variables of signals and bgs
def variables_type(nsubs):
    
    ### Name (str)
    name = input('Name of type: ')
    while not name:
        name = input('Name has to have a value: ')

    ### Number of subsamples (int)
    mes = 'Number of subsamples (default '+str(nsubs)+'): '
    nsubsamples = input(mes)    
    try:
        int(nsubsamples)
    except ValueError:
        nsubsamples = nsubs
    nsubsamples = int(nsubsamples)

    ### Drawable or not (1/0)
    drawable = input('Drawable (T/F, default T): ')
    if drawable == 'T' or drawable == 't' or drawable == 'True' or drawable == 'true' or drawable == 'TRUE' or drawable == '1': drawable = 1
    elif drawable == 'F' or drawable == 'f' or drawable == 'False' or drawable == 'false' or drawable == 'FALSE' or drawable == '0': drawable = 0
    else: drawable = 1

    ### Style (str)
    style = input('Style (default b1): ')
    if style:
        style = style
    else:
        style = 'b1'
    return name,nsubsamples,drawable,style

### Asking the variables of the subsamples
def variables_subsamples():

    ### Name (str)
    name = input('Name of subsample type: ')
    while not name:
        name = input('Name has to have a value: ')

    ### DSID (int)
    dsid = input('DSID (str): ')
    while not dsid:
        dsid = input('DSID (str): ')
    # while value_error_f(int,dsid) == False:
        # dsid = input('DSID (int): ')
    # dsid = int(dsid)

    ### Cross-section (float)
    cs = input('Cross-section (float, in pb): ')
    while value_error_f(float,cs) == False:
        cs = input('Cross-section (float, in pb): ')
    cs = float(cs)

    ### Weight (float, default 1)
    weight = input('Weight (float, default 1.0): ')
    try:
        float(weight)
    except ValueError:
        weight = 1
    weight = float(weight)

    return name,dsid,cs,weight

# Goes through the folder, if samples, xsections and weigths are found, can overwrite to them or ask for output path.
def file_in_dir_ask_ow(d,in_name):
    r = 0
    for subdir, dirs, files in os.walk(d):
        for f in files:
            if in_name in f:
                r = 1
                msg = in_name+' file found in '+os.path.join(subdir, f)+', write to that? [Y/n]: '
                ok = input(msg)
                if not ok:
                    fileinpath = os.path.join(subdir, f)
                if ok in ['n','N','0']:
                    fileinpath = input('Give '+in_name+' file to write to: ')
                else:
                    fileinpath = os.path.join(subdir, f)

    if r == 0:
        msg = 'Give '+in_name+' file to write to (default '+d+'/'+in_name+'.dat) : '
        fileinpath = input(msg)
        if not fileinpath:
            fileinpath = in_name
        fileinpath = d+'/'+fileinpath+'.dat'
        
    if exists(fileinpath):
        msg = 'Overwrite file '+fileinpath+'? [Y/n]: '
        ok = input(msg)
        if not ok:
            return fileinpath
        elif ok in ['n','N','0']:
            fileinpath = file_in_dir_ask_ow(d,in_name)
            return fileinpath
        else:
            return fileinpath
    else:
        return fileinpath
    

# The main function, goes through the folder and if samples file is found, asks to use it as a template. If not used or found, user can give path or initialize without defaults.
def inputsamples(modeln):
    r = 0
    for subdir, dirs, files in os.walk(modeln):
        for f in files:
            if 'sample' in f:
                r = 1
                msg = 'Samples file found in '+os.path.join(subdir, f)+', use that as defaults? [Y/n]: '
                ok = input(msg)
                if not ok:
                    fileinpath = os.path.join(subdir, f)
                if ok in ['n','N','0']:
                    fileinpath = input('Give a samples file (empty input starts without defaults): ')
                else:
                    fileinpath = os.path.join(subdir, f)
        if r == 0:
            msg = 'Samples file not found in folder.'
            print(msg)
            fileinpath = input('Give a samples file (empty input starts without defaults): ')
    
    ### If existing output file exists, use it to get default numbers of signals and bgs and subsamples
    if exists(fileinpath):
        file_lines = readOutputFile.read_file(fileinpath)
        nsigin,sigsinput,nbgin,bgsinput,nfixin,fixs = readOutputFile.num_of_sig_bg_sub(file_lines)
        print('sig,bg,fix')
        print(nsigin,sigsinput,nbgin,bgsinput,nfixin,fixs)
    else:
        print('File does not exist, using default values (number of signals = 1, bg = 0, subsamples = 0 for all).')
        nsigin = 1
        sigsinput = [0]
        nbgin = 0
        bgsinput = [0]
        nfixin = 5
        fixs = []

    ### Ask the name of the model and a possible already existing output file, open final output file and cross-section file
    # modeln = input('Name of the model (writing to files sample-<modelname>.txt, xsections-<modelname>.txt, and sumOfWeights-<modelname>.txt): ')
    filn = file_in_dir_ask_ow(modeln,'samples')
    # filn = 'sample-'+modeln+'.txt'
    outf = open(filn,'w')
    subsoutfname = file_in_dir_ask_ow(modeln,'xsections')
    # subsoutfname = 'xsections-'+modeln+'.txt'
    subsoutf = open(subsoutfname,'w')
    subswoutfname = file_in_dir_ask_ow(modeln,'sumOfWeights')
    # subswoutfname = 'weights-'+modeln+'.txt'
    subswoutf = open(subswoutfname,'w')    
    
    ### Ask the number of signal and bg samples (default either 1 and 0 or read from file)
    mes = 'Number of signal samples (default '+str(nsigin)+'): '
    nsig = input(mes)
    try:
        int(nsig)
    except ValueError:
        nsig = nsigin
    mes = 'Number of background samples (default '+str(nbgin)+'): '    
    nbg = input(mes)
    try:
        int(nbg)
    except ValueError:
        nbg = nbgin
    nsig = int(nsig)
    nbg = int(nbg)

    ### Typesize and samplesize
    typesize = nsig + nbg + 5
    samplesize = 0

    ### Go through signals, ask details
    signals = []
    for i in range(nsig):
        if len(sigsinput) != nsig:
            sigsinput.append(0)
        print('########### SIGNALS ###########')
        print('Signal number',i+1)
        sig_i = variables_type(sigsinput[i])
        samplesize += sig_i[1]
        subs = []
        for subi in range(sig_i[1]):
            print('--------SIGNAL SUBSAMPLES--------')
            print('Signal number',i+1, ', subsample number',subi+1)
            sub_i = variables_subsamples()
            subs.append([sub_i[0]] + [sub_i[1]] + [sub_i[2]] + [sub_i[3]])
        signals.append([sig_i[0]] + [subs] + [sig_i[2]] + [sig_i[3]])


        ### Go through bgs, ask details
    bgs = []
    for i in range(nbg):
        if len(bgsinput) != nbg:
            bgsinput.append(0)
        print('########### BACKGROUNDS ###########')
        print('Background number',i+1)
        bgs_i = variables_type(bgsinput[i])
        samplesize += bgs_i[1]
        subs = []
        for subi in range(bgs_i[1]):
            print('--------BACKGROUND SUBSAMPLES--------')
            print('BG number',i+1, ', subsample number',subi+1)
            sub_i = variables_subsamples()
            subs.append([sub_i[0]] + [sub_i[1]] + [sub_i[2]] + [sub_i[3]])
        bgs.append([bgs_i[0]] + [subs] + [bgs_i[2]] + [bgs_i[3]])


    outf.write('MODEL NAME = '+modeln+'\n')
    outf.write('TYPESIZE = '+str(typesize)+'\n')
    outf.write('SAMPLESIZE = '+str(samplesize)+'\n\n')

    ### Define fixed variables
    fixed = [0,1] 
    fixed_n = ['data','smbg','QCD','signal+smbg','QCDunc']
    fixed_draw = [1,0,0,0,1]
    fixed_style = ['e1','b1','b1','b1','e4']
    fixed_R = ['',['2','-3'],'',['2','-2'],'']
    bg = np.arange(2,2+nbg)
    signal = np.arange(nbg+2,nbg+2+nsig)
    fixed = fixed + [2+nsig+nbg] + [3+nsig+nbg] + [4+nsig+nbg]

    ### Print bgs to the file
    outf.write('\n## BACKGROUNDS ##\n')
    subsoutf.write('\n## BACKGROUNDS ##\n')
    subswoutf.write('\n## BACKGROUNDS ##\n')

    R = []
    incount = 1
    if len(bgs) == 0:
        outf.write('\n# No background given!\n')
    else:
        for i in range(len(bgs)):
            if len(bgs[i][1]) == 0:
                outf.write('\ntypeId-'+str(bg[i])+'-N = '+bgs[i][0]+'\n')
                outf.write('typeId-'+str(bg[i])+'-Drawable = '+str(bgs[i][2])+'\n')
                outf.write('typeId-'+str(bg[i])+'-Style = '+bgs[i][3]+'\n\n')
            else:
                incount += len(bgs[i][1])
                outf.write('\ntypeId-'+str(bg[i])+'-N = '+bgs[i][0]+'\n')
                outf.write('typeId-'+str(bg[i])+'-Rmin = '+str(incount-len(bgs[i][1]))+'\n')
                outf.write('typeId-'+str(bg[i])+'-Rmax = '+str(incount-1)+'\n')        
                outf.write('typeId-'+str(bg[i])+'-Drawable = '+str(bgs[i][2])+'\n')
                outf.write('typeId-'+str(bg[i])+'-Style = '+bgs[i][3]+'\n\n')

            if len(bgs[i][1]) == 0:
                outf.write('\n# No subsamples input for given BG!\n')
                subsoutf.write('\n# No subsamples input for given BG!\n')
                subswoutf.write('\n# No subsamples input for given BG!\n')
            else:
                for j in range(len(bgs[i][1])):
                    outf.write('sampleId-'+str(bg[i])+str(j+1)+'-F = '+str(bgs[i][1][j][1])+'\n')
                    subsoutf.write('\nsampleId-'+str(bg[i])+str(j+1)+'-F = '+str(bgs[i][1][j][1])+'\n')
                    subsoutf.write('sampleId-'+str(bg[i])+str(j+1)+'-CS = '+str(bgs[i][1][j][2])+'\n')
                    subswoutf.write('\nsampleId-'+str(bg[i])+str(j+1)+'-F = '+str(bgs[i][1][j][1])+'\n')
                    subswoutf.write('sampleId-'+str(bg[i])+str(j+1)+'-weight = '+str(bgs[i][1][j][3])+'\n')


    ### Print sigs to the file
    outf.write('\n## SIGNALS ##\n')
    subsoutf.write('\n## SIGNALS ##\n')
    subswoutf.write('\n## SIGNALS ##\n')
    if len(signals) == 0:
        outf.write('\n# No signals given!\n')
    else:
        for i in range(len(signals)):

            if len(signals[i][1]) == 0:
                outf.write('\ntypeId-'+str(signal[i])+'-N = '+signals[i][0]+'\n')
                outf.write('typeId-'+str(signal[i])+'-Drawable = '+str(signals[i][2])+'\n')
                outf.write('typeId-'+str(signal[i])+'-Style = '+signals[i][3]+'\n\n')
            else:
                incount += len(signals[i][1])
                outf.write('\ntypeId-'+str(signal[i])+'-N = '+signals[i][0]+'\n')
                outf.write('typeId-'+str(signal[i])+'-Rmin = '+str(incount-len(signals[i][1]))+'\n')
                outf.write('typeId-'+str(signal[i])+'-Rmax = '+str(incount-1)+'\n')        
                outf.write('typeId-'+str(signal[i])+'-Drawable = '+str(signals[i][2])+'\n')
                outf.write('typeId-'+str(signal[i])+'-Style = '+signals[i][3]+'\n\n')

            if len(signals[i][1]) == 0:
                outf.write('\n# No subsamples input for given signal!\n')
                subsoutf.write('\n# No subsamples input for given signal!\n')
                subswoutf.write('\n# No subsamples input for given signal!\n')            
            else:
                for j in range(len(signals[i][1])):
                    outf.write('sampleId-'+str(signal[i])+str(j+1)+'-F = '+str(signals[i][1][j][1])+'\n')
                    subsoutf.write('\nsampleId-'+str(signal[i])+str(j+1)+'-F = '+str(signals[i][1][j][1])+'\n')
                    subsoutf.write('sampleId-'+str(signal[i])+str(j+1)+'-CS = '+str(signals[i][1][j][2])+'\n')
                    subswoutf.write('\nsampleId-'+str(signal[i])+str(j+1)+'-F = '+str(signals[i][1][j][1])+'\n')
                    subswoutf.write('sampleId-'+str(signal[i])+str(j+1)+'-weight = '+str(signals[i][1][j][3])+'\n')


    ### Print fixed to the file
    outf.write('\n## FIXED TYPES ##\n')
    for i in range(len(fixed)):
        outf.write('\ntypeId-'+str(fixed[i])+'-N = '+fixed_n[i]+'\n')
        if isinstance(fixed_R[i],list):
            outf.write('typeId-'+str(fixed[i])+'-Rmin = '+fixed_R[i][0]+'\n')
            outf.write('typeId-'+str(fixed[i])+'-Rmax = '+fixed_R[i][1]+'\n')
        outf.write('typeId-'+str(fixed[i])+'-Drawable = '+str(fixed_draw[i])+'\n')
        outf.write('typeId-'+str(fixed[i])+'-Style = '+fixed_style[i]+'\n\n')

    outf.close()
    subsoutf.close()
    subswoutf.close()
    return None

# To run the script without the wrapper, asks a model directory.
def main():
    d = input("Input a model directory (or '.' to use the current folder): ")
    while not d:
        d = input("Input model directory (or '.' to use the current folder): ")
    if not exists(d):
        print("Directory not found, exiting.")
        sys.exit()

    inputsamples(d)

if __name__ == "__main__":
    main()
