#
# Autogenerated by Thrift Compiler (0.9.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
require 5.6.0;
use strict;
use warnings;
use Thrift;

use thrift::adept::common::Types;
use thrift::adept::common::ItemService;

# HELPER FUNCTIONS AND STRUCTURES

package thrift::adept::common::AnomalousTextService_getConfidence_args;
use base qw(Class::Accessor);

sub new {
                  my $classname = shift;
                  my $self      = {};
                  my $vals      = shift || {};
                  return bless ($self, $classname);
}

sub getName {
                  return 'AnomalousTextService_getConfidence_args';
                }

sub read {
                  my ($self, $input) = @_;
                  my $xfer  = 0;
                  my $fname;
                  my $ftype = 0;
                  my $fid   = 0;
                  $xfer += $input->readStructBegin(\$fname);
                  while (1) 
                  {
                    $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                    if ($ftype == TType::STOP) {
                      last;
                    }
                    SWITCH: for($fid)
                    {
                        $xfer += $input->skip($ftype);
                    }
                    $xfer += $input->readFieldEnd();
                  }
                  $xfer += $input->readStructEnd();
                  return $xfer;
                }

sub write {
                  my ($self, $output) = @_;
                  my $xfer   = 0;
                  $xfer += $output->writeStructBegin('AnomalousTextService_getConfidence_args');
                  $xfer += $output->writeFieldStop();
                  $xfer += $output->writeStructEnd();
                  return $xfer;
                }

package thrift::adept::common::AnomalousTextService_getConfidence_result;
use base qw(Class::Accessor);
thrift::adept::common::AnomalousTextService_getConfidence_result->mk_accessors( qw( success ) );

sub new {
                  my $classname = shift;
                  my $self      = {};
                  my $vals      = shift || {};
                  $self->{success} = undef;
                  if (UNIVERSAL::isa($vals,'HASH')) {
                    if (defined $vals->{success}) {
                      $self->{success} = $vals->{success};
                    }
                  }
                  return bless ($self, $classname);
}

sub getName {
                  return 'AnomalousTextService_getConfidence_result';
                }

sub read {
                  my ($self, $input) = @_;
                  my $xfer  = 0;
                  my $fname;
                  my $ftype = 0;
                  my $fid   = 0;
                  $xfer += $input->readStructBegin(\$fname);
                  while (1) 
                  {
                    $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                    if ($ftype == TType::STOP) {
                      last;
                    }
                    SWITCH: for($fid)
                    {
                      /^0$/ && do{                      if ($ftype == TType::DOUBLE) {
                        $xfer += $input->readDouble(\$self->{success});
                      } else {
                        $xfer += $input->skip($ftype);
                      }
                      last; };
                        $xfer += $input->skip($ftype);
                    }
                    $xfer += $input->readFieldEnd();
                  }
                  $xfer += $input->readStructEnd();
                  return $xfer;
                }

sub write {
                  my ($self, $output) = @_;
                  my $xfer   = 0;
                  $xfer += $output->writeStructBegin('AnomalousTextService_getConfidence_result');
                  if (defined $self->{success}) {
                    $xfer += $output->writeFieldBegin('success', TType::DOUBLE, 0);
                    $xfer += $output->writeDouble($self->{success});
                    $xfer += $output->writeFieldEnd();
                  }
                  $xfer += $output->writeFieldStop();
                  $xfer += $output->writeStructEnd();
                  return $xfer;
                }

package thrift::adept::common::AnomalousTextService_getDocument_args;
use base qw(Class::Accessor);

sub new {
                  my $classname = shift;
                  my $self      = {};
                  my $vals      = shift || {};
                  return bless ($self, $classname);
}

sub getName {
                  return 'AnomalousTextService_getDocument_args';
                }

sub read {
                  my ($self, $input) = @_;
                  my $xfer  = 0;
                  my $fname;
                  my $ftype = 0;
                  my $fid   = 0;
                  $xfer += $input->readStructBegin(\$fname);
                  while (1) 
                  {
                    $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                    if ($ftype == TType::STOP) {
                      last;
                    }
                    SWITCH: for($fid)
                    {
                        $xfer += $input->skip($ftype);
                    }
                    $xfer += $input->readFieldEnd();
                  }
                  $xfer += $input->readStructEnd();
                  return $xfer;
                }

sub write {
                  my ($self, $output) = @_;
                  my $xfer   = 0;
                  $xfer += $output->writeStructBegin('AnomalousTextService_getDocument_args');
                  $xfer += $output->writeFieldStop();
                  $xfer += $output->writeStructEnd();
                  return $xfer;
                }

package thrift::adept::common::AnomalousTextService_getDocument_result;
use base qw(Class::Accessor);
thrift::adept::common::AnomalousTextService_getDocument_result->mk_accessors( qw( success ) );

sub new {
                  my $classname = shift;
                  my $self      = {};
                  my $vals      = shift || {};
                  $self->{success} = undef;
                  if (UNIVERSAL::isa($vals,'HASH')) {
                    if (defined $vals->{success}) {
                      $self->{success} = $vals->{success};
                    }
                  }
                  return bless ($self, $classname);
}

sub getName {
                  return 'AnomalousTextService_getDocument_result';
                }

sub read {
                  my ($self, $input) = @_;
                  my $xfer  = 0;
                  my $fname;
                  my $ftype = 0;
                  my $fid   = 0;
                  $xfer += $input->readStructBegin(\$fname);
                  while (1) 
                  {
                    $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                    if ($ftype == TType::STOP) {
                      last;
                    }
                    SWITCH: for($fid)
                    {
                      /^0$/ && do{                      if ($ftype == TType::STRUCT) {
                        $self->{success} = new thrift::adept::common::Document();
                        $xfer += $self->{success}->read($input);
                      } else {
                        $xfer += $input->skip($ftype);
                      }
                      last; };
                        $xfer += $input->skip($ftype);
                    }
                    $xfer += $input->readFieldEnd();
                  }
                  $xfer += $input->readStructEnd();
                  return $xfer;
                }

sub write {
                  my ($self, $output) = @_;
                  my $xfer   = 0;
                  $xfer += $output->writeStructBegin('AnomalousTextService_getDocument_result');
                  if (defined $self->{success}) {
                    $xfer += $output->writeFieldBegin('success', TType::STRUCT, 0);
                    $xfer += $self->{success}->write($output);
                    $xfer += $output->writeFieldEnd();
                  }
                  $xfer += $output->writeFieldStop();
                  $xfer += $output->writeStructEnd();
                  return $xfer;
                }

package thrift::adept::common::AnomalousTextService_getExplanation_args;
use base qw(Class::Accessor);

sub new {
                  my $classname = shift;
                  my $self      = {};
                  my $vals      = shift || {};
                  return bless ($self, $classname);
}

sub getName {
                  return 'AnomalousTextService_getExplanation_args';
                }

sub read {
                  my ($self, $input) = @_;
                  my $xfer  = 0;
                  my $fname;
                  my $ftype = 0;
                  my $fid   = 0;
                  $xfer += $input->readStructBegin(\$fname);
                  while (1) 
                  {
                    $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                    if ($ftype == TType::STOP) {
                      last;
                    }
                    SWITCH: for($fid)
                    {
                        $xfer += $input->skip($ftype);
                    }
                    $xfer += $input->readFieldEnd();
                  }
                  $xfer += $input->readStructEnd();
                  return $xfer;
                }

sub write {
                  my ($self, $output) = @_;
                  my $xfer   = 0;
                  $xfer += $output->writeStructBegin('AnomalousTextService_getExplanation_args');
                  $xfer += $output->writeFieldStop();
                  $xfer += $output->writeStructEnd();
                  return $xfer;
                }

package thrift::adept::common::AnomalousTextService_getExplanation_result;
use base qw(Class::Accessor);
thrift::adept::common::AnomalousTextService_getExplanation_result->mk_accessors( qw( success ) );

sub new {
                  my $classname = shift;
                  my $self      = {};
                  my $vals      = shift || {};
                  $self->{success} = undef;
                  if (UNIVERSAL::isa($vals,'HASH')) {
                    if (defined $vals->{success}) {
                      $self->{success} = $vals->{success};
                    }
                  }
                  return bless ($self, $classname);
}

sub getName {
                  return 'AnomalousTextService_getExplanation_result';
                }

sub read {
                  my ($self, $input) = @_;
                  my $xfer  = 0;
                  my $fname;
                  my $ftype = 0;
                  my $fid   = 0;
                  $xfer += $input->readStructBegin(\$fname);
                  while (1) 
                  {
                    $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                    if ($ftype == TType::STOP) {
                      last;
                    }
                    SWITCH: for($fid)
                    {
                      /^0$/ && do{                      if ($ftype == TType::STRING) {
                        $xfer += $input->readString(\$self->{success});
                      } else {
                        $xfer += $input->skip($ftype);
                      }
                      last; };
                        $xfer += $input->skip($ftype);
                    }
                    $xfer += $input->readFieldEnd();
                  }
                  $xfer += $input->readStructEnd();
                  return $xfer;
                }

sub write {
                  my ($self, $output) = @_;
                  my $xfer   = 0;
                  $xfer += $output->writeStructBegin('AnomalousTextService_getExplanation_result');
                  if (defined $self->{success}) {
                    $xfer += $output->writeFieldBegin('success', TType::STRING, 0);
                    $xfer += $output->writeString($self->{success});
                    $xfer += $output->writeFieldEnd();
                  }
                  $xfer += $output->writeFieldStop();
                  $xfer += $output->writeStructEnd();
                  return $xfer;
                }

package thrift::adept::common::AnomalousTextService_setExplanation_args;
use base qw(Class::Accessor);
thrift::adept::common::AnomalousTextService_setExplanation_args->mk_accessors( qw( explanation ) );

sub new {
                  my $classname = shift;
                  my $self      = {};
                  my $vals      = shift || {};
                  $self->{explanation} = undef;
                  if (UNIVERSAL::isa($vals,'HASH')) {
                    if (defined $vals->{explanation}) {
                      $self->{explanation} = $vals->{explanation};
                    }
                  }
                  return bless ($self, $classname);
}

sub getName {
                  return 'AnomalousTextService_setExplanation_args';
                }

sub read {
                  my ($self, $input) = @_;
                  my $xfer  = 0;
                  my $fname;
                  my $ftype = 0;
                  my $fid   = 0;
                  $xfer += $input->readStructBegin(\$fname);
                  while (1) 
                  {
                    $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                    if ($ftype == TType::STOP) {
                      last;
                    }
                    SWITCH: for($fid)
                    {
                      /^1$/ && do{                      if ($ftype == TType::STRING) {
                        $xfer += $input->readString(\$self->{explanation});
                      } else {
                        $xfer += $input->skip($ftype);
                      }
                      last; };
                        $xfer += $input->skip($ftype);
                    }
                    $xfer += $input->readFieldEnd();
                  }
                  $xfer += $input->readStructEnd();
                  return $xfer;
                }

sub write {
                  my ($self, $output) = @_;
                  my $xfer   = 0;
                  $xfer += $output->writeStructBegin('AnomalousTextService_setExplanation_args');
                  if (defined $self->{explanation}) {
                    $xfer += $output->writeFieldBegin('explanation', TType::STRING, 1);
                    $xfer += $output->writeString($self->{explanation});
                    $xfer += $output->writeFieldEnd();
                  }
                  $xfer += $output->writeFieldStop();
                  $xfer += $output->writeStructEnd();
                  return $xfer;
                }

package thrift::adept::common::AnomalousTextService_setExplanation_result;
use base qw(Class::Accessor);

sub new {
                  my $classname = shift;
                  my $self      = {};
                  my $vals      = shift || {};
                  return bless ($self, $classname);
}

sub getName {
                  return 'AnomalousTextService_setExplanation_result';
                }

sub read {
                  my ($self, $input) = @_;
                  my $xfer  = 0;
                  my $fname;
                  my $ftype = 0;
                  my $fid   = 0;
                  $xfer += $input->readStructBegin(\$fname);
                  while (1) 
                  {
                    $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                    if ($ftype == TType::STOP) {
                      last;
                    }
                    SWITCH: for($fid)
                    {
                        $xfer += $input->skip($ftype);
                    }
                    $xfer += $input->readFieldEnd();
                  }
                  $xfer += $input->readStructEnd();
                  return $xfer;
                }

sub write {
                  my ($self, $output) = @_;
                  my $xfer   = 0;
                  $xfer += $output->writeStructBegin('AnomalousTextService_setExplanation_result');
                  $xfer += $output->writeFieldStop();
                  $xfer += $output->writeStructEnd();
                  return $xfer;
                }

package thrift::adept::common::AnomalousTextServiceIf;

use strict;
use base qw(thrift::adept::common::ItemServiceIf);

sub getConfidence{
  my $self = shift;

  die 'implement interface';
}

sub getDocument{
  my $self = shift;

  die 'implement interface';
}

sub getExplanation{
  my $self = shift;

  die 'implement interface';
}

sub setExplanation{
  my $self = shift;
  my $explanation = shift;

  die 'implement interface';
}

package thrift::adept::common::AnomalousTextServiceRest;

use strict;
use base qw(thrift::adept::common::ItemServiceRest);

sub getConfidence{
                  my ($self, $request) = @_;

                  return $self->{impl}->getConfidence();
                }

sub getDocument{
                  my ($self, $request) = @_;

                  return $self->{impl}->getDocument();
                }

sub getExplanation{
                  my ($self, $request) = @_;

                  return $self->{impl}->getExplanation();
                }

sub setExplanation{
                  my ($self, $request) = @_;

                  my $explanation = ($request->{'explanation'}) ? $request->{'explanation'} : undef;
                  return $self->{impl}->setExplanation($explanation);
                }

package thrift::adept::common::AnomalousTextServiceClient;

use base qw(thrift::adept::common::ItemServiceClient);
use base qw(thrift::adept::common::AnomalousTextServiceIf);
sub new {
                  my ($classname, $input, $output) = @_;
                  my $self      = {};
                  $self = $classname->SUPER::new($input, $output);
                  return bless($self,$classname);
}

sub getConfidence{
  my $self = shift;

                                    $self->send_getConfidence();
                  return $self->recv_getConfidence();
}

sub send_getConfidence{
  my $self = shift;

                  $self->{output}->writeMessageBegin('getConfidence', TMessageType::CALL, $self->{seqid});
                  my $args = new thrift::adept::common::AnomalousTextService_getConfidence_args();
                  $args->write($self->{output});
                  $self->{output}->writeMessageEnd();
                  $self->{output}->getTransport()->flush();
}

sub recv_getConfidence{
  my $self = shift;

                  my $rseqid = 0;
                  my $fname;
                  my $mtype = 0;

                  $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                  if ($mtype == TMessageType::EXCEPTION) {
                    my $x = new TApplicationException();
                    $x->read($self->{input});
                    $self->{input}->readMessageEnd();
                    die $x;
                  }
                  my $result = new thrift::adept::common::AnomalousTextService_getConfidence_result();
                  $result->read($self->{input});
                  $self->{input}->readMessageEnd();

                  if (defined $result->{success} ) {
                    return $result->{success};
                  }
                  die "getConfidence failed: unknown result";
}
sub getDocument{
  my $self = shift;

                                    $self->send_getDocument();
                  return $self->recv_getDocument();
}

sub send_getDocument{
  my $self = shift;

                  $self->{output}->writeMessageBegin('getDocument', TMessageType::CALL, $self->{seqid});
                  my $args = new thrift::adept::common::AnomalousTextService_getDocument_args();
                  $args->write($self->{output});
                  $self->{output}->writeMessageEnd();
                  $self->{output}->getTransport()->flush();
}

sub recv_getDocument{
  my $self = shift;

                  my $rseqid = 0;
                  my $fname;
                  my $mtype = 0;

                  $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                  if ($mtype == TMessageType::EXCEPTION) {
                    my $x = new TApplicationException();
                    $x->read($self->{input});
                    $self->{input}->readMessageEnd();
                    die $x;
                  }
                  my $result = new thrift::adept::common::AnomalousTextService_getDocument_result();
                  $result->read($self->{input});
                  $self->{input}->readMessageEnd();

                  if (defined $result->{success} ) {
                    return $result->{success};
                  }
                  die "getDocument failed: unknown result";
}
sub getExplanation{
  my $self = shift;

                                    $self->send_getExplanation();
                  return $self->recv_getExplanation();
}

sub send_getExplanation{
  my $self = shift;

                  $self->{output}->writeMessageBegin('getExplanation', TMessageType::CALL, $self->{seqid});
                  my $args = new thrift::adept::common::AnomalousTextService_getExplanation_args();
                  $args->write($self->{output});
                  $self->{output}->writeMessageEnd();
                  $self->{output}->getTransport()->flush();
}

sub recv_getExplanation{
  my $self = shift;

                  my $rseqid = 0;
                  my $fname;
                  my $mtype = 0;

                  $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                  if ($mtype == TMessageType::EXCEPTION) {
                    my $x = new TApplicationException();
                    $x->read($self->{input});
                    $self->{input}->readMessageEnd();
                    die $x;
                  }
                  my $result = new thrift::adept::common::AnomalousTextService_getExplanation_result();
                  $result->read($self->{input});
                  $self->{input}->readMessageEnd();

                  if (defined $result->{success} ) {
                    return $result->{success};
                  }
                  die "getExplanation failed: unknown result";
}
sub setExplanation{
  my $self = shift;
  my $explanation = shift;

                                    $self->send_setExplanation($explanation);
                  $self->recv_setExplanation();
}

sub send_setExplanation{
  my $self = shift;
  my $explanation = shift;

                  $self->{output}->writeMessageBegin('setExplanation', TMessageType::CALL, $self->{seqid});
                  my $args = new thrift::adept::common::AnomalousTextService_setExplanation_args();
                  $args->{explanation} = $explanation;
                  $args->write($self->{output});
                  $self->{output}->writeMessageEnd();
                  $self->{output}->getTransport()->flush();
}

sub recv_setExplanation{
  my $self = shift;

                  my $rseqid = 0;
                  my $fname;
                  my $mtype = 0;

                  $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                  if ($mtype == TMessageType::EXCEPTION) {
                    my $x = new TApplicationException();
                    $x->read($self->{input});
                    $self->{input}->readMessageEnd();
                    die $x;
                  }
                  my $result = new thrift::adept::common::AnomalousTextService_setExplanation_result();
                  $result->read($self->{input});
                  $self->{input}->readMessageEnd();

                  return;
}
package thrift::adept::common::AnomalousTextServiceProcessor;

use strict;
use base qw(thrift::adept::common::ItemServiceProcessor);

sub process {
                    my ($self, $input, $output) = @_;
                    my $rseqid = 0;
                    my $fname  = undef;
                    my $mtype  = 0;

                    $input->readMessageBegin(\$fname, \$mtype, \$rseqid);
                    my $methodname = 'process_'.$fname;
                    if (!$self->can($methodname)) {
                      $input->skip(TType::STRUCT);
                      $input->readMessageEnd();
                      my $x = new TApplicationException('Function '.$fname.' not implemented.', TApplicationException::UNKNOWN_METHOD);
                      $output->writeMessageBegin($fname, TMessageType::EXCEPTION, $rseqid);
                      $x->write($output);
                      $output->writeMessageEnd();
                      $output->getTransport()->flush();
                      return;
                    }
                    $self->$methodname($rseqid, $input, $output);
                    return 1;
}

sub process_getConfidence {
                    my ($self, $seqid, $input, $output) = @_;
                    my $args = new thrift::adept::common::AnomalousTextService_getConfidence_args();
                    $args->read($input);
                    $input->readMessageEnd();
                    my $result = new thrift::adept::common::AnomalousTextService_getConfidence_result();
                    $result->{success} = $self->{handler}->getConfidence();
                    $output->writeMessageBegin('getConfidence', TMessageType::REPLY, $seqid);
                    $result->write($output);
                    $output->writeMessageEnd();
                    $output->getTransport()->flush();
}

sub process_getDocument {
                    my ($self, $seqid, $input, $output) = @_;
                    my $args = new thrift::adept::common::AnomalousTextService_getDocument_args();
                    $args->read($input);
                    $input->readMessageEnd();
                    my $result = new thrift::adept::common::AnomalousTextService_getDocument_result();
                    $result->{success} = $self->{handler}->getDocument();
                    $output->writeMessageBegin('getDocument', TMessageType::REPLY, $seqid);
                    $result->write($output);
                    $output->writeMessageEnd();
                    $output->getTransport()->flush();
}

sub process_getExplanation {
                    my ($self, $seqid, $input, $output) = @_;
                    my $args = new thrift::adept::common::AnomalousTextService_getExplanation_args();
                    $args->read($input);
                    $input->readMessageEnd();
                    my $result = new thrift::adept::common::AnomalousTextService_getExplanation_result();
                    $result->{success} = $self->{handler}->getExplanation();
                    $output->writeMessageBegin('getExplanation', TMessageType::REPLY, $seqid);
                    $result->write($output);
                    $output->writeMessageEnd();
                    $output->getTransport()->flush();
}

sub process_setExplanation {
                    my ($self, $seqid, $input, $output) = @_;
                    my $args = new thrift::adept::common::AnomalousTextService_setExplanation_args();
                    $args->read($input);
                    $input->readMessageEnd();
                    my $result = new thrift::adept::common::AnomalousTextService_setExplanation_result();
                    $self->{handler}->setExplanation($args->explanation);
                    $output->writeMessageBegin('setExplanation', TMessageType::REPLY, $seqid);
                    $result->write($output);
                    $output->writeMessageEnd();
                    $output->getTransport()->flush();
}

1;
